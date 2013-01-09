#!/usr/bin/perl -w

=back

  Copyright (C) 2013, Molnar Karoly <molnarkaroly@users.sf.net>

    This software is provided 'as-is', without any express or implied
    warranty.  In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
       claim that you wrote the original software. If you use this software
       in a product, an acknowledgment in the product documentation would be
       appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
       misrepresented as being the original software.

    3. This notice may not be removed or altered from any source distribution.

================================================================================

    This program disassembles the hex files. It assumes that the hex file
    contains MCS51 instructions.

    Proposal for use: ./mcs51-disasm.pl -M 8052.h program.hex

  $Id$
=cut

use strict;
use warnings;
use 5.12.0;                     # when (regex)

use constant FALSE	=> 0;
use constant TRUE	=> 1;

use constant TAB_LENGTH	=> 8;

################################################################################

use constant INHX8M			=> 0;
use constant INHX32			=> 2;

use constant INHX_DATA_REC		=> 0;
use constant INHX_EOF_REC		=> 1;
use constant INHX_EXT_LIN_ADDR_REC	=> 4;

use constant EMPTY			=> -1;

use constant COUNT_SIZE			=> 2;
use constant ADDR_SIZE			=> 4;
use constant TYPE_SIZE			=> 2;
use constant BYTE_SIZE			=> 2;
use constant CRC_SIZE			=> 2;
use constant HEADER_SIZE		=> (COUNT_SIZE + ADDR_SIZE + TYPE_SIZE);
use constant MIN_LINE_LENGTH		=> (HEADER_SIZE + CRC_SIZE);

use constant MCS51_ROM_SIZE		=> 0x10000;

################################################################################

my $PROGRAM = 'mcs51-disasm.pl';

my $border0 = ('-' x 79);
my $border1 = ('#' x 79);

my @default_paths =
  (
  '/usr/share/sdcc/include/mcs51',
  '/usr/local/share/sdcc/include/mcs51'
  );

my $default_include_path = '';
my $include_path = '';
my $hex_file = '';
my $map_file = '';
my $header_file = '';

my $verbose = 0;

my @rom = ();
my $rom_size = MCS51_ROM_SIZE;
my %const_areas_by_address = ();

=back
	Structure of one element of %labels_by_address:

	{
	NAME    => '',
	TYPE    => 0,
	PRINTED => FALSE
	}
=cut

use constant LABEL => 1;
use constant SUB   => 2;

my %labels_by_address = ();
my $max_label_addr = 0;

my %sfrs_by_address = ();
my %sfrs_by_names   = ();
my %bits_by_address = ();

my %variables_by_address = ();
my $max_variable_addr = 0;

	# Sizes of the instructions.

my @instruction_sizes =
  (
  1, 2, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  3, 2, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  3, 2, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  3, 2, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 1, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 1, 1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  3, 2, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 1, 1, 3, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
  1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
  );

use constant DPL => 0x82;
use constant DPH => 0x83;
use constant PSW => 0xD0;

my $DPTR;
my @R_regs;

my $prev_is_jump;

use constant ALIGN_SIZE => 5;

=back
	The structure of one element of the %blocks_by_address hash:

	{
	TYPE  => 0,
	ADDR  => 0,
	SIZE  => 0,
	LABEL => 0
	}
=cut

use constant BLOCK_INSTR => 0x00;
use constant BLOCK_CONST => 0x01;
use constant BLOCK_EMPTY => 0x02;

use constant BL_LABEL_NONE  => 0x00;
use constant BL_LABEL_SUB   => 0x11;
use constant BL_LABEL_LABEL => 0x12;

my %blocks_by_address = ();

my %interrupts_by_address =
  (
  0x0000 => 'System_init',
  0x0003 => 'Int0_interrupt',
  0x000B => 'Timer0_interrupt',
  0x0013 => 'Int1_interrupt',
  0x001B => 'Timer1_interrupt',
  0x0023 => 'Uart_interrupt',
  0x002B => 'Timer2_interrupt',
  0x0033 => 'Int2_interrupt',
  0x003B => 'Int3_interrupt'
  );

################################################################################
################################################################################

my %pp_defines = ();            # Value of definitions.

my @pp_conditions = ();
my @pp_else_conditions = ();
my $pp_level = 0;               # Shows the lowest level.
my $embed_level;

#   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#@@@@@@@@@@@@@@@@@@@@@@@@                             @@@@@@@@@@@@@@@@@@@@@@@@@@
#@@@@@@@@@@@@@@@@@@@@@@@  This a simple preprocessor.  @@@@@@@@@@@@@@@@@@@@@@@@@
#@@@@@@@@@@@@@@@@@@@@@@@@                             @@@@@@@@@@@@@@@@@@@@@@@@@@
# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	# Examines that the parameter is defined or not defined.

sub _defined($)
  {
  return defined($pp_defines{$_[0]});
  }

#-------------------------------------------------------------------------------

	# Records a definition.

sub define($)
  {
  my ($Name) = ($_[0] =~ /^(\S+)/o);
  my $Body = ${^POSTMATCH};

  $Body =~ s/^\s+//o;

  die "define(): This definition already exists: \"$Name\"\n" if (_defined($Name));

        # The definition is in fact unnecessary.
  $pp_defines{$Name} = $Body;
  }

#-------------------------------------------------------------------------------

	# Delete a definition.

sub undefine($)
  {
  delete($pp_defines{$_[0]});
  }

#-------------------------------------------------------------------------------

	# Evaluation of the #if give a boolean value. This procedure preserves it.

sub if_condition($)
  {
  my $Val = $_[0];

  push(@pp_conditions, $Val);
  push(@pp_else_conditions, $Val);
  ++$pp_level;
  }

#-------------------------------------------------------------------------------

	# Evaluation of the #else give a boolean value. This procedure preserves it.

sub else_condition($$)
  {
  my ($File, $Line_number) = @_;

  die "else_condition(): The ${Line_number}th line of $File there is a #else, but does not belong him #if.\n" if ($pp_level <= 0);

  my $last = $#pp_conditions;

  if ($last > 0 && $pp_conditions[$last - 1])
    {
    $pp_conditions[$last] = ($pp_else_conditions[$#pp_else_conditions]) ? FALSE : TRUE;
    }
  else
    {
    $pp_conditions[$last] = FALSE;
    }
  }

#-------------------------------------------------------------------------------

	# Closes a logical unit which starts with a #if.

sub endif_condition($$)
  {
  my ($File, $Line_number) = @_;

  die "endif_condition(): The ${Line_number}th line of $File there is a #endif, but does not belong him #if.\n" if ($pp_level <= 0);

  pop(@pp_conditions);
  pop(@pp_else_conditions);
  --$pp_level;
  }

#-------------------------------------------------------------------------------

sub reset_preprocessor()
  {
  %pp_defines = ();
  @pp_conditions = ();
  push(@pp_conditions, TRUE);
  @pp_else_conditions = ();
  push(@pp_else_conditions, FALSE);
  $pp_level = 0;
  }

#-------------------------------------------------------------------------------

        # This the preprocessor.

sub run_preprocessor($$$$)
  {
  my ($Fname, $Function, $Line, $Line_number) = @_;

  if ($Line =~ /^#\s*ifdef\s+(\S+)$/o)
    {
    if ($pp_conditions[$#pp_conditions])
      {
        # The ancestor is valid, therefore it should be determined that
        # the descendants what kind.

      if_condition(_defined($1));
      }
    else
      {
        # The ancestor is invalid, so the descendants will invalid also.

      if_condition(FALSE);
      }
    }
  elsif ($Line =~ /^#\s*ifndef\s+(\S+)$/o)
    {
    if ($pp_conditions[$#pp_conditions])
      {
        # The ancestor is valid, therefore it should be determined that
        # the descendants what kind.

      if_condition(! _defined($1));
      }
    else
      {
        # The ancestor is invalid, so the descendants will invalid also.

      if_condition(FALSE);
      }
    }
  elsif ($Line =~ /^#\s*else/o)
    {
    else_condition($Fname, $Line_number);
    }
  elsif ($Line =~ /^#\s*endif/o)
    {
    endif_condition($Fname, $Line_number);
    }
  elsif ($Line =~ /^#\s*define\s+(.+)$/o)
    {
        # This level is valid, so it should be recorded in the definition.

    define($1) if ($pp_conditions[$#pp_conditions]);
    }
  elsif ($Line =~ /^#\s*undef\s+(.+)$/o)
    {
        # This level is valid, so it should be deleted in the definition.

    undefine($1) if ($pp_conditions[$#pp_conditions]);
    }
  elsif ($pp_conditions[$#pp_conditions])
    {
        # This is a valid line. (The whole magic is in fact therefore there is.)

    $Function->($Line);
    }
  }

################################################################################
################################################################################
################################################################################

sub basename($)
  {
  return ($_[0] =~ /([^\/]+)$/) ? $1 : '';
  }

#-------------------------------------------------------------------------------

sub param_exist($$)
  {
  die "This option \"$_[0]\" requires a parameter.\n" if ($_[1] > $#ARGV);
  }

#-------------------------------------------------------------------------------

sub Log
  {
  return if (pop(@_) > $verbose);
  foreach (@_) { print STDERR $_; }
  print STDERR "\n";
  }

#-------------------------------------------------------------------------------

sub str2int($)
  {
  my $Str = $_[0];

  return hex($1)   if ($Str =~ /^0x([[:xdigit:]]+)$/io);
  return int($Str) if ($Str =~ /^-?\d+$/o);

  die "str2int(): This string not integer: \"$Str\"";
  }

#-------------------------------------------------------------------------------

	#
	# Before print, formats the $Text.
	#

sub align($$)
  {
  my $Text = $_[0];
  my $al   = $_[1] - int(length($Text) / TAB_LENGTH);

	# One tab will surely becomes behind it.
  $al = 1 if ($al < 1);

  return ($Text . "\t" x $al);
  }

#-------------------------------------------------------------------------------

	#
	# Multiple file test.
	#

sub is_file_ok($)
  {
  my $File = $_[0];

  if (! -e $File)
    {
    print STDERR "$PROGRAM: Not exists -> \"$File\"\n";
    exit(1);
    }

  if (! -f $File)
    {
    print STDERR "$PROGRAM: Not file -> \"$File\"\n";
    exit(1);
    }

  if (! -r $File)
    {
    print STDERR "$PROGRAM: Can not read -> \"$File\"\n";
    exit(1);
    }

  if (! -s $File)
    {
    print STDERR "$PROGRAM: Empty file -> \"$File\"\n";
    exit(1);
    }
  }

#-------------------------------------------------------------------------------

	#
	# Initializes the @rom array.
	#

sub init_mem($$)
  {
  my ($Start, $End) = @_;

  @rom[$Start .. $End] = ((EMPTY) x ($End - $Start + 1));
  }

#-------------------------------------------------------------------------------

	#
	# Store values of the $Code to $AddrRef address.
	#

sub store_code($$)
  {
  my ($Code, $AddrRef) = @_;

  if ($$AddrRef >= $rom_size)
    {
    printf STDERR "Warning, this address (0x%04X) outside the code area (0x%04X)!\n", $$AddrRef, $rom_size - 1;
    }

  Log(sprintf("rom[0x%08X] = 0x%02X", $$AddrRef, $Code), 9);
  $rom[$$AddrRef++] = $Code;
  }

#-------------------------------------------------------------------------------

        #
        # Reads contents of the $Hex.
        #

sub read_hex($)
  {
  my $Hex = $_[0];
  my $addr_H;
  my $format = INHX32;

  if (! open(IN, '<', $Hex))
    {
    print STDERR "$PROGRAM : Could not open. -> \"$Hex\"\n";
    exit(1);
    }

  $addr_H = 0;

  while (<IN>)
    {
    chomp;
    s/\r$//o;

    my $len = length() - 1;

    if ($len < MIN_LINE_LENGTH)
      {
      close(IN);
      print STDERR "$PROGRAM: ${.}th line <- Shorter than %u character.\n", MIN_LINE_LENGTH;
      exit(1);
      }

    Log("$..(1) (\"$_\") length() = " . length(), 7);

    my $bytecount = int(($len - MIN_LINE_LENGTH) / BYTE_SIZE);

    my $binrec = pack('H*', substr($_, 1));

    if (unpack('%8C*', $binrec) != 0)
      {
      close(IN);
      print STDERR "$PROGRAM: $Hex <- Crc error. (${.}th line \"$_\").\n";
      exit(1);
      }

    my ($count, $addr, $type, $bytes) = unpack('CnCX4Cx3/a', $binrec);

    my @codes = unpack('C*', $bytes);

    Log(sprintf("$..(2) (\"$_\") count = $count, bytecount = $bytecount, addr = 0x%04X, type = $type", $addr), 7);

    if ($type == INHX_EOF_REC)
      {
      last;
      }
    elsif ($type == INHX_EXT_LIN_ADDR_REC)
      {
      $addr_H = unpack('n', $bytes);	# big-endian

      Log(sprintf("$..(3) (\"$_\") addr_H = 0x%04X\n", $addr_H), 7);

      $format = INHX32;
      Log('format = INHX32', 7);
      next;
      }
    elsif ($type != INHX_DATA_REC)
      {
      close(IN);
      printf STDERR "$PROGRAM: $Hex <- Unknown type of record: 0x%02X (${.}th line \"$_\").\n", $type;
      exit(1);
      }

    if ($bytecount == $count)			# INHX32
      {
      if ($format == INHX8M)
	{
	close(IN);
	print STDERR "$PROGRAM: $Hex <- Mixed format of file (${.}th line \"$_\").\n";
	exit(1);
	}

      my $addr32 = ($addr_H << 16) | $addr;

      map { store_code($_, \$addr32) } @codes;
      }
    elsif ($bytecount == ($count * BYTE_SIZE))	# INHX8M
      {
      if ($format == INHX32)
	{
	close(IN);
	print STDERR "$PROGRAM: $Hex <- Mixed format of file (${.}th line \"$_\").\n";
	exit(1);
	}

      map { store_code($_, \$addr) } @codes;
      }
    else
      {
      close(IN);
      print STDERR "$PROGRAM: $Hex <- Wrong format of file (${.}th line \"$_\").\n";
      exit(1);
      }
    } # while (<IN>)

  close(IN);
  }

#-------------------------------------------------------------------------------

	#
	# Determines that the $Address belongs to a constant.
	#

sub is_constant($)
  {
  my $Address = $_[0];

  foreach (keys(%const_areas_by_address))
    {
    return TRUE if ($_ <= $Address && $Address <= $const_areas_by_address{$_});
    }

  return FALSE;
  }

#-------------------------------------------------------------------------------

sub add_block($$$$)
  {
  my ($Address, $Type, $Size, $LabelType) = @_;

  if (! defined($blocks_by_address{$Address}))
    {
    $blocks_by_address{$Address} = {
				   TYPE  => $Type,
				   ADDR  => $Address,
				   SIZE  => $Size,
				   LABEL => $LabelType
				   };
    }
  else
    {
    my $ref = $blocks_by_address{$Address};

    $ref->{SIZE}  = $Size      if ($Size > 0);
    $ref->{LABEL} = $LabelType if ($LabelType != BL_LABEL_NONE);
    }
  }

#-------------------------------------------------------------------------------

	#
	# Store address entry of a procedure.
	#

sub add_func_label($)
  {
  my $Address = $_[0];

  if ($Address < 0)
    {
    Log(sprintf("add_func_label(): This address (0x%04X) negative!", $Address), 2);
    return;
    }

  if (! defined($blocks_by_address{$Address}))
    {
    Log(sprintf("add_func_label(): This address (0x%04X) does not shows an instruction!", $Address), 2);
    return;
    }

  if (is_constant($Address))
    {
    Log(sprintf("add_func_label(): This address (0x%04X) outside the code area (0x%04X)!", $Address, $rom_size - 1), 2);
    return;
    }

  if (! defined($labels_by_address{$Address}))
    {
    $max_label_addr = $Address if ($max_label_addr < $Address);
    }

  $labels_by_address{$Address}->{TYPE} = SUB;
  add_block($Address, BLOCK_INSTR, 0, BL_LABEL_SUB);
  }

#-------------------------------------------------------------------------------

	#
	# Store a label.
	#

sub add_jump_label($$)
  {
  my ($TargetAddr, $SourceAddr) = @_;
  my $label;

  if ($TargetAddr < 0)
    {
    Log(sprintf("add_jump_label(): This address (0x%04X) negative!", $TargetAddr), 2);
    return;
    }

  if (! defined($blocks_by_address{$TargetAddr}))
    {
    Log(sprintf("add_jump_label(): This address (0x%04X) does not shows an instruction!", $TargetAddr), 2);
    return;
    }

  if (is_constant($TargetAddr))
    {
    Log(sprintf("add_jump_label(): This address (0x%04X) outside the code area (0x%04X)!", $TargetAddr, $rom_size - 1), 2);
    return;
    }

  if (! defined($labels_by_address{$TargetAddr}))
    {
    $labels_by_address{$TargetAddr}->{TYPE} = LABEL;
    $label = \%{$labels_by_address{$TargetAddr}};

	#
	# This is the interrupt vector table. The handlers gets unique names.
	#

    if (defined($interrupts_by_address{$SourceAddr}))
      {
      $label->{NAME} = $interrupts_by_address{$SourceAddr};
      $label->{TYPE} = SUB;
      }

    $max_label_addr = $TargetAddr if ($max_label_addr < $TargetAddr);
    $label->{PRINTED} = FALSE;
    add_block($TargetAddr, BLOCK_INSTR, 0, BL_LABEL_LABEL);
    }
  }

################################################################################
################################################################################

use constant MAP_NULL   => 0;
use constant MAP_BORDER => 1;
use constant MAP_AREA   => 2;
use constant MAP_CABS   => 3;
use constant MAP_CODE0  => 4;
use constant MAP_CODE1  => 5;
use constant MAP_DATA   => 6;
use constant MAP_CONST  => 7;

        #
        # If exists the map file, then extracts out of it the labels,
        # variables and some segments.
        #

sub read_map_file()
  {
  my ($addr, $name, $state, $label);

  return if ($map_file eq '');

  $state = MAP_NULL;

  if (! open(MAP, '<', $map_file))
    {
    print STDERR "$PROGRAM : Could not open. -> \"$map_file\"\n";
    exit(1);
    }

  while (<MAP>)
    {
    chomp;
    s/\r$//o;

    if ($state == MAP_NULL)
      {
      $state = MAP_BORDER if (/^Area\s+/io);
      }
    elsif ($state == MAP_BORDER)
      {
      $state = MAP_AREA if (/^-+\s+/o);
      }
    elsif ($state == MAP_AREA)
      {
      if (/^CABS\s+/o)
	{
	$state = MAP_CABS;
	}
      elsif (/^(HOME|CSEG)\s+/o)
	{
	$state = MAP_CODE0;
	}
      elsif (/^GSINIT\d+\s+/o)
	{
	$state = MAP_CODE1;
	}
      elsif (/^DSEG\s+/o)
	{
	$state = MAP_DATA;
	}
      elsif (/^CONST\s+([[:xdigit:]]+)\s+([[:xdigit:]]+)\s+/o)
	{
	my ($start, $size) = (hex($1), hex($2));

	$const_areas_by_address{$start} = $start + $size - 1;
	$state = MAP_CONST;
	}
      else
	{
	$state = MAP_NULL;
	}
      }
    elsif ($state == MAP_CABS)
      {
      if (/^.ASxxxx Linker\s+/io)
        {
        $state = MAP_NULL;
        }
      elsif (/^C:\s+([[:xdigit:]]+)\s+(\S+)/o)
	{
	($addr, $name) = (hex($1), $2);

	if ($name eq 's_CONST' || $name eq 's_XINIT')
	  {
	# C:   000001E8  s_CONST
	# C:   00000215  s_XINIT

	  $label = \%{$labels_by_address{$addr}};
	  $label->{NAME} = $name;
	  $label->{TYPE} = LABEL;
	  }
	}
      } # elsif ($state == MAP_CABS)
    elsif ($state == MAP_CODE0 || $state == MAP_CODE1)
      {
      if (/^.ASxxxx Linker\s+/io)
        {
        $state = MAP_NULL;
        }
      elsif (/^C:\s+([[:xdigit:]]+)\s+(\S+)/o)
	{
	# C:   00000040  __mcs51_genXINIT
	# C:   00000061  __mcs51_genRAMCLEAR
	# C:   00000067  __mcs51_genXRAMCLEAR
	# C:   00000086  _Uart_int                          main
	# C:   000000CE  _toHexChar                         main
	# C:   000001E4  __sdcc_external_startup            _startup

	($addr, $name) = (hex($1), $2);

	$label = \%{$labels_by_address{$addr}};
	$label->{NAME} = $name;
	$label->{TYPE} = ($state == MAP_CODE0) ? SUB : LABEL;
	}
      } # elsif ($state == MAP_CODE0 || $state == MAP_CODE1)
    elsif ($state == MAP_DATA)
      {
      if (/^.ASxxxx Linker\s+/io)
        {
        $state = MAP_NULL;
        }
      elsif (/^\s*([[:xdigit:]]+)\s+(\S+)/o)
	{
	# 00000039  _counter                           data
	# 0000004C  _flash_read_PARM_2                 flash

	($addr, $name) = (hex($1), $2);

	$variables_by_address{$addr} = $name if (! defined($variables_by_address{$addr}));

	$max_variable_addr = $addr if ($max_variable_addr < $addr);
	}
      } # elsif ($state == MAP_DATA)
    elsif ($state == MAP_CONST)
      {
      $state = MAP_NULL if (/^.ASxxxx Linker\s+/io);
      }
    } # while (<MAP>)

  close(MAP);
  }

#-------------------------------------------------------------------------------

	#
	# There are some variables that are multi-byte. However, only
	# the LSB byte of having a name. This procedure gives a name
	# for the higher-significant bytes.
	#

sub fix_multi_byte_variables()
  {
  my $prev_addr = EMPTY;
  my $prev_name = '';
  my ($i, $var_size);

  foreach (sort {$a <=> $b} keys(%variables_by_address))
    {
    if ($prev_addr > EMPTY)
      {
      $var_size = $_ - $prev_addr;

      if ($var_size > 1)
	{
	# This is a multi-byte variable.

	for ($i = 1; $i < $var_size; ++$i)
	  {
	  $variables_by_address{$prev_addr + $i} = "($prev_name + $i)";
	  }
	}
      }

    $prev_addr = $_;
    $prev_name = $variables_by_address{$_};
    }
  }

#-------------------------------------------------------------------------------

        #
        # If there is left in yet so label that has no name, this here get one.
        # 

sub add_names_labels()
  {
  my ($addr, $fidx, $label, $lidx);

  $fidx = 0;
  $lidx = 0;
  for ($addr = 0; $addr <= $max_label_addr; ++$addr)
    {
    if (defined($labels_by_address{$addr}))
      {
      $label = \%{$labels_by_address{$addr}};

      next if (defined($label->{NAME}) && $label->{NAME} ne '');

      if ($label->{TYPE} == SUB)
	{
	$label->{NAME} = sprintf("Function_%03u", $fidx++);
	}
      elsif ($label->{TYPE} == LABEL)
	{
	$label->{NAME} = sprintf("Label_%03u", $lidx++);
	}
      }
    }
  }

################################################################################
################################################################################

=back
        Instruction set of the 8051 family:

	NOP				00000000
	AJMP	addr11			aaa00001 aaaaaaaa		a10 a9 a8 1 0 0 0 1	a7-a0
	LJMP	addr16			00000010 aaaaaaaa aaaaaaaa	a15-a8 a7-a0	absolute address
	RR	A			00000011
	INC	A			00000100
	INC	direct			00000101 aaaaaaaa		register address
	INC	@Ri			0000011i			R0 .. R1
	INC	Rn			00001rrr			R0 .. R7
	JBC	bit, rel		00010000 bbbbbbbb rrrrrrrr	bit address	relative address
	ACALL	addr11			aaa10001 aaaaaaaa		a10 a9 a8 1 0 0 0 1	a7-a0
	LCALL	addr16			00010010 aaaaaaaa aaaaaaaa	a15-a8 a7-a0	absolute address
	RRC	A			00010011
	DEC	A			00010100
	DEC	direct			00010101 aaaaaaaa		register address
	DEC	@Ri			0001011i			R0 .. R1
	DEC	Rn			00011rrr			R0 .. R7
	JB	bit, rel		00100000 bbbbbbbb rrrrrrrr	bit address	relative address
	RET				00100010
	RL	A			00100011
	ADD	A, #data		00100100 dddddddd		adat
	ADD	A, direct		00100101 aaaaaaaa		register address
	ADD	A, @Ri			0010011i			R0 .. R1
	ADD	A, Rn			00101rrr			R0 .. R7
	JNB	bit, rel		00110000 bbbbbbbb rrrrrrrr	bit address	relative address
	RETI				00110010
	RLC	A			00110011
	ADDC	A, #data		00110100 dddddddd		adat
	ADDC	A, direct		00110101 aaaaaaaa		register address
	ADDC	A, @Ri			0011011i			R0 .. R1
	ADDC	A, Rn			00111rrr			R0 .. R7
	JC	rel			01000000 rrrrrrrr 		relative address
	ORL	direct, A		01000010 aaaaaaaa		register address
	ORL	direct, #data		01000011 aaaaaaaa dddddddd	register address	adat
	ORL	A, #data		01000100 dddddddd		adat
	ORL	A, direct		01000101 aaaaaaaa		register address
	ORL	A, @Ri			0100011i			R0 .. R1
	ORL	A, Rn			01001rrr		        R0 .. R7
	JNC	rel			01010000 rrrrrrrr 		relative address
	ANL	direct, A		01010010 aaaaaaaa		register address
	ANL	direct, #data		01010011 aaaaaaaa dddddddd	register address	adat
	ANL	A, #data		01010100 dddddddd		adat
	ANL	A, direct		01010101 aaaaaaaa		register address
	ANL	A, @Ri			0101011i			R0 .. R1
	ANL	A, Rn			01011rrr			R0 .. R7
	JZ	rel			01100000 rrrrrrrr 		relative address
	XRL	direct, A		01100010 aaaaaaaa		register address
	XRL	direct, #data		01100011 aaaaaaaa dddddddd	register address	adat
	XRL	A, #data		01100100 dddddddd		adat
	XRL	A, direct		01100101 aaaaaaaa		register address
	XRL	A, @Ri			0110011i			R0 .. R1
	XRL	A, Rn			01101rrr			R0 .. R7
	JNZ	rel			01110000 rrrrrrrr 		relative address
	ORL	C, bit			01110010 bbbbbbbb		bit address
	JMP	@A+DPTR			01110011
	MOV	A, #data		01110100 dddddddd		adat
	MOV	direct, #data		01110101 aaaaaaaa dddddddd	register address	adat
	MOV	@Ri, #data		0111011i dddddddd		adat
	MOV	Rn, #data		01111rrr dddddddd		R0 .. R7	adat
	SJMP	rel			10000000 rrrrrrrr		relative address
	ANL	C, bit			10000010 bbbbbbbb		bit address
	MOVC	A, @A+PC		10000011
	DIV	AB			10000100
	MOV	direct, direct		10000101 aaaaaaaa aaaaaaaa	forrás reg.	cél reg.
	MOV	direct, @Ri		1000011i aaaaaaaa		R0 .. R1	register address
	MOV	direct, Rn		10001rrr aaaaaaaa		R0 .. R7	register address
	MOV	DPTR, #data16		10010000 dddddddd dddddddd	d15-d8 d7-d0
	MOV	bit, C			10010010 bbbbbbbb		bit address
	MOVC	A, @A+DPTR		10010011
	SUBB	A, #data		10010100 dddddddd		adat
	SUBB	A, direct		10010101 aaaaaaaa		register address
	SUBB	A, @Ri			1001011i			R0 .. R1
	SUBB	A, Rn			10011rrr			R0 .. R7
	ORL	C, /bit			10100000 bbbbbbbb		bit address
	MOV	C, bit			10100010 bbbbbbbb		bit address
	INC	DPTR			10100011
	MUL	AB			10100100
	MOV	@Ri, direct		1010011i aaaaaaaa		register address
	MOV	Rn, direct		10101rrr aaaaaaaa		R0 .. R7	register address
	ANL	C, /bit			10110000 bbbbbbbb		bit address
	CPL	bit			10110010 bbbbbbbb		bit address
	CPL	C			10110011
	CJNE	A, #data, rel		10110100 dddddddd rrrrrrrr	adat		relative address
	CJNE	A, direct, rel		10110101 aaaaaaaa rrrrrrrr	register address	relative address
	CJNE	@Ri, #data, rel		1011011i dddddddd rrrrrrrr	R0 .. R1 	data	relative address
	CJNE	Rn, #data, rel		10111rrr dddddddd rrrrrrrr	R0 .. R7 	data	relative address
	PUSH	direct			11000000 aaaaaaaa		register address
	CLR	bit			11000010 bbbbbbbb		bit address
	CLR	C			11000011
	SWAP	A			11000100
	XCH	A, direct		11000101 aaaaaaaa		register address
	XCH	A, @Ri			1100011i			R0 .. R1
	XCH	A, Rn			11001rrr			R0 .. R7
	POP	direct			11010000 aaaaaaaa		register address
	SETB	bit			11010010 bbbbbbbb		bit address
	SETB	C			11010011
	DA	A			11010100
	DJNZ	direct, rel		11010101 aaaaaaaa rrrrrrrr	register address	relative address
	XCHD	A, @Ri			1101011i			R0 .. R1
	DJNZ	Rn, rel			11011rrr rrrrrrrr		R0 .. R7	relative address
	MOVX	A, @DPTR		11100000
	MOVX	A, @Ri			1110001i			R0 .. R1
	CLR	A			11100100
	MOV	A, direct		11100101 aaaaaaaa		register address	The "MOV A, ACC" invalid intruction.
	MOV	A, @Ri			1110011i			R0 .. R1
	MOV	A, Rn			11101rrr			R0 .. R7
	MOVX	@DPTR, A		11110000
	MOVX	@Ri, A			1111001i			R0 .. R1
	CPL	A			11110100
	MOV	direct, A		11110101 aaaaaaaa		register address
	MOV	@Ri, A			1111011i			R0 .. R1
	MOV	Rn, A			11111rrr			R0 .. R7
=cut

#-------------------------------------------------------------------------------

	#
	# Expand a relative offset value.
	#

sub expand_offset($)
  {
  my $Offset = $_[0];

  return ($Offset & 0x80) ? -(($Offset ^ 0xFF) + 1) : $Offset;
  }

#-------------------------------------------------------------------------------

        #
	# Finds address of branchs and procedures.
        #

sub label_finder($)
  {
  my $BlockRef = $_[0];
  my ($block, $instr_size, $address, $instr);
  my ($addr, $parm0, $parm1, $instr_mask0, $instr_mask1, $instr_mask2);

  $address     = $BlockRef->{ADDR};
  $instr_size  = $BlockRef->{SIZE};
  $instr       = $rom[$address];

  $instr_mask0 = $instr & 0x1F;
  $instr_mask1 = $instr & 0xFE;
  $instr_mask2 = $instr & 0xF8;

  if ($instr_mask0 == 0x01)
    {
        # AJMP	addr11			aaa00001 aaaaaaaa		a10 a9 a8 1 0 0 0 1	a7-a0

    $parm0 = $rom[$address + 1];
    $addr  = (($address + $instr_size) & 0xF800) | (($instr & 0xE0) << 3) | $parm0;
    add_jump_label($addr, $address);
    }
  elsif ($instr_mask0 == 0x11)
    {
	# ACALL	addr11			aaa10001 aaaaaaaa		a10 a9 a8 1 0 0 0 1	a7-a0

    $parm0 = $rom[$address + 1];
    $addr  = (($address + $instr_size) & 0xF800) | (($instr & 0xE0) << 3) | $parm0;
    add_func_label($addr);
    }
  elsif ($instr_mask1 == 0xB6 || $instr_mask2 == 0xB8)
    {
	# CJNE	@Ri, #data, rel		1011011i dddddddd rrrrrrrr	R0 .. R1 	data		relative address
	# CJNE	Rn, #data, rel		10111rrr dddddddd rrrrrrrr	R0 .. R7 	data		relative address

    $parm0 = $rom[$address + 1];
    $parm1 = $rom[$address + 2];
    $addr  = $address + $instr_size + expand_offset($parm1);
    add_jump_label($addr, -1);
    }
  elsif ($instr_mask2 == 0xD8)
    {
	# DJNZ	Rn, rel			11011rrr rrrrrrrr		R0 .. R7	relative address

    $parm0 = $rom[$address + 1];
    $addr  = $address + $instr_size + expand_offset($parm0);
    add_jump_label($addr, -1);
    }
  elsif ($instr == 0x02)
    {
	# LJMP	addr16			00000010 aaaaaaaa aaaaaaaa	a15-a8 a7-a0	absolute address

    $parm0 = $rom[$address + 1];
    $parm1 = $rom[$address + 2];
    $addr  = ($parm0 << 8) | $parm1;
    add_jump_label($addr, $address);
    }
  elsif ($instr == 0x12)
    {
	# LCALL	addr16			00010010 aaaaaaaa aaaaaaaa	a15-a8 a7-a0	absolute address

    $parm0 = $rom[$address + 1];
    $parm1 = $rom[$address + 2];
    $addr  = ($parm0 << 8) | $parm1;
    add_func_label($addr);
    }
  elsif ($instr == 0x10 || $instr == 0x20 ||
	 $instr == 0x30 || $instr == 0xB4 ||
	 $instr == 0xB5 || $instr == 0xD5)
    {
	# JBC	bit, rel		00010000 bbbbbbbb rrrrrrrr	bit address		relative address
	# JB	bit, rel		00100000 bbbbbbbb rrrrrrrr	bit address		relative address
	# JNB	bit, rel		00110000 bbbbbbbb rrrrrrrr	bit address		relative address
	# CJNE	A, #data, rel		10110100 dddddddd rrrrrrrr	data			relative address
	# CJNE	A, direct, rel		10110101 aaaaaaaa rrrrrrrr	register address	relative address
	# DJNZ	direct, rel		11010101 aaaaaaaa rrrrrrrr	register address	relative address

    $parm0 = $rom[$address + 1];
    $parm1 = $rom[$address + 2];
    $addr  = $address + $instr_size + expand_offset($parm1);
    add_jump_label($addr, -1);
    }
  elsif ($instr == 0x40 || $instr == 0x50 ||
	 $instr == 0x60 || $instr == 0x70 ||
	 $instr == 0x80)
    {
	# JC	rel			01000000 rrrrrrrr 		relative address
	# JNC	rel			01010000 rrrrrrrr 		relative address
	# JZ	rel			01100000 rrrrrrrr 		relative address
	# JNZ	rel			01110000 rrrrrrrr 		relative address
	# SJMP	rel			10000000 rrrrrrrr		relative address

    $parm0 = $rom[$address + 1];
    $addr  = $address + $instr_size + expand_offset($parm0);
    add_jump_label($addr, -1);
    }
  }

#-------------------------------------------------------------------------------

	#
	# If exists a variable name wich belong to the $Address, then returns it.
	# Otherwise, returns the address.
	#

sub regname($$)
  {
  my ($Address, $StrRef) = @_;
  my $str;

  if ($Address <= 0x1F)
    {
	# This register belongs to one of the register bank.

    my $bank = ($Address >> 3) & 3;
    my $reg  = $Address & 7;

    $str = "R${reg}<#$bank>";
    $$StrRef = $str;

    if (defined($variables_by_address{$Address}))
      {
      my $var = $variables_by_address{$Address};

      printf STDERR ("This address (0x%02X) belongs to two names: \"$str\" and \"$var\"\n", $Address);
      }
    }
  elsif (defined($sfrs_by_address{$Address}))
    {
    $str = $sfrs_by_address{$Address};
    $$StrRef = $str;
    }
  elsif (defined($variables_by_address{$Address}))
    {
    $str = sprintf "0x%02X", $Address;
    $$StrRef = "[$str]";
    $str = $variables_by_address{$Address};
    }
  else
    {
    $str = sprintf "0x%02X", $Address;
    $$StrRef = "[$str]";
    }

  return $str;
  }

#-------------------------------------------------------------------------------

	#
	# If exists a bit name wich belong to the $Address, then returns it.
	# Otherwise, returns the address.
	#

sub bitname($$)
  {
  my ($Address, $StrRef) = @_;
  my $str;

  if (defined($bits_by_address{$Address}))
    {
    $str = $bits_by_address{$Address};
    $$StrRef = $str;
    }
  else
    {
    $str = sprintf "0x%02X", $Address;
    $$StrRef = "[$str]";
    }

  return $str;
  }

#-------------------------------------------------------------------------------

	#
	# If exists a label name wich belong to the $Address, then returns it.
	# Otherwise, returns the address.
	#

sub labelname($)
  {
  my $Address = $_[0];

  return (defined($labels_by_address{$Address})) ? $labels_by_address{$Address}->{NAME} : (sprintf "0x%04X", $Address);
  }

#-------------------------------------------------------------------------------

	#
	# Auxiliary procedure of prints.
	#

sub print_3($$$)
  {
  print "$_[0]\t" . align($_[1], ALIGN_SIZE) . "; $_[2]\n";
  }

#-------------------------------------------------------------------------------

	#
	# Invalidates the DPTR and the Rx registers.
	#

sub invalidate_DPTR_Rx()
  {
  $DPTR = EMPTY;
  @R_regs[0 .. 7] = ((EMPTY) x 8);
  }

#-------------------------------------------------------------------------------

	#
	# Invalidates the DPTR or the Rx registers.
	#

sub invalidate_reg($)
  {
  my $Address = $_[0];

  if ($Address == DPL || $Address == DPH)
    {
    $DPTR = EMPTY;
    }
  elsif ($Address <= 0x1F)
    {
    $R_regs[$Address & 7] = EMPTY;
    }
  }

#-------------------------------------------------------------------------------

	#
	# Carries out the operations with the R registers.
	#

use constant Rx_INV => 0;
use constant Rx_INC => 1;
use constant Rx_DEC => 2;
use constant Rx_MOV => 3;

sub operation_R_reg
  {
  my $Rx   = shift(@_);
  my $Oper = shift(@_);
  my $r;

  if ($Oper == Rx_INV)
    {
    $R_regs[$Rx] = EMPTY;
    }
  elsif ($Oper == Rx_INC)
    {
    $r = $R_regs[$Rx];

    if ($r != EMPTY)
      {
      ++$r;
      $R_regs[$Rx] = $r & 0xFF;
      return TRUE;
      }
    }
  elsif ($Oper == Rx_DEC)
    {
    $r = $R_regs[$Rx];

    if ($r != EMPTY)
      {
      --$r;
      $R_regs[$Rx] = $r & 0xFF;
      return TRUE;
      }
    }
  elsif ($Oper == Rx_MOV)
    {
    $R_regs[$Rx] = shift(@_) & 0xFF;
    return TRUE;
    }

  return FALSE;
  }

#-------------------------------------------------------------------------------

	#
	# If possible, returns the character.
	#

sub present_char($)
  {
  my $Ch = $_[0];

  if ($Ch >= ord(' ') && $Ch < 0x7F)
    {
    return sprintf " ('%c')", $Ch;
    }
  elsif ($Ch == 0x09)
    {
    return " ('\\t')";
    }
  elsif ($Ch == 0x0A)
    {
    return " ('\\n')";
    }
  elsif ($Ch == 0x0D)
    {
    return " ('\\r')";
    }

  return '';
  }

#-------------------------------------------------------------------------------

	#
	# Decodes value of the $Ch.
	#

sub decode_char($)
  {
  my $Ch = $_[0];

  if ($Ch >= ord(' ') && $Ch < 0x7F)
    {
    return sprintf "'%c'", $Ch;
    }
  elsif ($Ch == 0x09)
    {
    return "'\\t'";
    }
  elsif ($Ch == 0x0A)
    {
    return "'\\n'";
    }
  elsif ($Ch == 0x0D)
    {
    return "'\\r'";
    }

  return sprintf "0x%02X", $Ch;
  }

#-------------------------------------------------------------------------------

        #
        # Decodes the $BlockRef.
        #

sub instruction_decoder($)
  {
  my $BlockRef = $_[0];
  my ($block, $instr_size, $address, $instr, $parm0, $parm1, $addr);
  my ($instr_mask0, $instr_mask1, $instr_mask2);
  my ($ri_regs, $rn_regs);
  my ($ri_name, $rn_name);
  my ($rb0, $rb1, $name0, $name1, $str0, $str1);

  $address    = $BlockRef->{ADDR};
  $instr_size = $BlockRef->{SIZE};
  $instr      = $rom[$address];

  printf "0x%04X: %02X", $address, $instr;

  if ($instr_size == 1)
    {
    print "\t\t";
    }
  elsif ($instr_size == 2)
    {
    $parm0 = $rom[$address + 1];
    printf " %02X\t\t", $parm0;
    }
  elsif ($instr_size == 3)
    {
    $parm0 = $rom[$address + 1];
    $parm1 = $rom[$address + 2];
    printf " %02X %02X\t", $parm0, $parm1;
    }
  else
    {
    print "\t";
    }

  $instr_mask0 = $instr & 0x1F;

  $instr_mask1 = $instr & 0xFE;
  $ri_regs     = $instr & 0x01;
  $ri_name     = "R$ri_regs";

  $instr_mask2 = $instr & 0xF8;
  $rn_regs     = $instr & 0x07;
  $rn_name     = "R$rn_regs";

  $prev_is_jump = FALSE;

  if ($instr_mask0 == 0x01)
    {
        # AJMP	addr11			aaa00001 aaaaaaaa		a10 a9 a8 1 0 0 0 1	a7-a0

    $rb1   = (($instr & 0xE0) << 3) | $parm0;
    $addr  = (($address + $instr_size) & 0xF800) | $rb1;
    $rb0   = labelname($addr);
    $name0 = sprintf "0x%04X", $rb1;
    $str0  = ($address == $addr) ? ' (endless loop)' : '';
    $str1  = sprintf "0x%04X", $addr;
    print_3('ajmp', $rb0, "Jumps hither: $str1 (PC += $instr_size, PC(10-0) = $name0)$str0");
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr_mask0 == 0x11)
    {
	# ACALL	addr11			aaa10001 aaaaaaaa		a10 a9 a8 1 0 0 0 1	a7-a0

    $rb1   = (($instr & 0xE0) << 3) | $parm0;
    $addr  = (($address + $instr_size) & 0xF800) | $rb1;
    $rb0   = labelname($addr);
    $str0  = sprintf "0x%04X", $rb1;
    $str1  = sprintf "0x%04X", $addr;
    print_3('acall', $rb0, "Calls this: $str1 (PC += $instr_size, [++SP] = PCL, [++SP] = PCH, PC(10-0) = $str0)");
    invalidate_DPTR_Rx();
    }
  elsif ($instr_mask1 == 0x06)
    {
	# INC	@Ri			0000011i			R0 .. R1

    print_3('inc', "\@$ri_name", "++[$ri_name]");
    invalidate_DPTR_Rx();
    }
  elsif ($instr_mask1 == 0x16)
    {
	# DEC	@Ri			0001011i			R0 .. R1

    print_3('dec', "\@$ri_name", "--[$ri_name]");
    invalidate_DPTR_Rx();
    }
  elsif ($instr_mask1 == 0x26)
    {
	# ADD	A, @Ri			0010011i			R0 .. R1

    print_3('add', "A, \@$ri_name", "ACC += [$ri_name]");
    }
  elsif ($instr_mask1 == 0x36)
    {
	# ADDC	A, @Ri			0011011i			R0 .. R1

    print_3('addc', "A, \@$ri_name", "ACC += [$ri_name] + CY");
    }
  elsif ($instr_mask1 == 0x46)
    {
	# ORL	A, @Ri			0100011i			R0 .. R1

    print_3('orl', "A, \@$ri_name", "ACC |= [$ri_name]");
    }
  elsif ($instr_mask1 == 0x56)
    {
	# ANL	A, @Ri			0101011i			R0 .. R1

    print_3('anl', "A, \@$ri_name", "ACC &= [$ri_name]");
    }
  elsif ($instr_mask1 == 0x66)
    {
	# XRL	A, @Ri			0110011i			R0 .. R1

    print_3('xrl', "A, \@$ri_name", "ACC ^= [$ri_name]");
    }
  elsif ($instr_mask1 == 0x76)
    {
	# MOV	@Ri, #data		0111011i dddddddd		data

    $rb0   = sprintf "0x%02X", $parm0;
    $str0  = present_char($parm0);
    print_3('mov', "\@$ri_name, #$rb0", "[$ri_name] = $rb0$str0");
    invalidate_DPTR_Rx();
    }
  elsif ($instr_mask1 == 0x86)
    {
	# MOV	direct, @Ri		1000011i aaaaaaaa		R0 .. R1	register address

    $rb0   = regname($parm0, \$name0);
    print_3('mov', "$rb0, \@$ri_name", "$name0 = [$ri_name]");
    invalidate_DPTR_Rx();
    }
  elsif ($instr_mask1 == 0x96)
    {
	# SUBB	A, @Ri			1001011i			R0 .. R1

    print_3('subb', "A, \@$ri_name", "ACC -= [$ri_name] + CY");
    }
  elsif ($instr_mask1 == 0xA6)
    {
	# MOV	@Ri, direct		1010011i aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('mov', "\@$ri_name, $rb0", "[$ri_name] = $name0");
    invalidate_DPTR_Rx();
    }
  elsif ($instr_mask1 == 0xB6)
    {
	# CJNE	@Ri, #data, rel		1011011i dddddddd rrrrrrrr	R0 .. R1 	data		relative address

    $addr  = $address + $instr_size + expand_offset($parm1);
    $rb0   = labelname($addr);
    $str0  = sprintf "0x%02X", $parm0;
    $str1  = sprintf "0x%04X", $addr;
    print_3('cjne', "\@$ri_name, #$str0, $rb0", "If ([$ri_name] != $str0) then jumps hither: $str1");
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr_mask1 == 0xC6)
    {
	# XCH	A, @Ri			1100011i			R0 .. R1

    print_3('xch', "A, \@$ri_name", "ACC <-> [$ri_name]");
    invalidate_DPTR_Rx();
    }
  elsif ($instr_mask1 == 0xD6)
    {
	# XCHD	A, @Ri			1101011i			R0 .. R1

    print_3('xchd', "A, \@$ri_name", "ACC(3-0) <-> [$ri_name](3-0)");
    invalidate_DPTR_Rx();
    }
  elsif ($instr_mask1 == 0xE2)
    {
	# MOVX	A, @Ri			1110001i			R0 .. R1

    print_3('movx', "A, \@$ri_name", "ACC = XRAM[$ri_name]");
    }
  elsif ($instr_mask1 == 0xE6)
    {
	# MOV	A, @Ri			1110011i			R0 .. R1

    print_3('mov', "A, \@$ri_name", "ACC = [$ri_name]");
    }
  elsif ($instr_mask1 == 0xF2)
    {
	# MOVX	@Ri, A			1111001i			R0 .. R1

    print_3('movx', "\@$ri_name, A", "XRAM[$ri_name] = ACC");
    invalidate_DPTR_Rx();
    }
  elsif ($instr_mask1 == 0xF6)
    {
	# MOV	@Ri, A			1111011i			R0 .. R1

    print_3('mov', "\@$ri_name, A", "[$ri_name] = ACC");
    invalidate_DPTR_Rx();
    }
  elsif ($instr_mask2 == 0x08)
    {
	# INC	Rn			00001rrr			R0 .. R7

    if (operation_R_reg($rn_regs, Rx_INC))
      {
      $str0 = sprintf "0x%02X", $R_regs[$rn_regs];
      print_3('inc', $rn_name, "++$rn_name ($str0)");
      }
    else
      {
      print_3('inc', $rn_name, "++$rn_name");
      }
    }
  elsif ($instr_mask2 == 0x18)
    {
	# DEC	Rn			00011rrr			R0 .. R7

    if (operation_R_reg($rn_regs, Rx_DEC))
      {
      $str0 = sprintf "0x%02X", $R_regs[$rn_regs];
      print_3('dec', $rn_name, "--$rn_name ($str0)");
      }
    else
      {
      print_3('dec', $rn_name, "--$rn_name");
      }
    }
  elsif ($instr_mask2 == 0x28)
    {
	# ADD	A, Rn			00101rrr			R0 .. R7

    print_3('add', "A, $rn_name", "ACC += $rn_name");
    }
  elsif ($instr_mask2 == 0x38)
    {
	# ADDC	A, Rn			00111rrr			R0 .. R7

    print_3('addc', "A, $rn_name", "ACC += $rn_name + CY");
    }
  elsif ($instr_mask2 == 0x48)
    {
	# ORL	A, Rn			01001rrr		        R0 .. R7

    print_3('orl', "A, $rn_name", "ACC |= $rn_name");
    }
  elsif ($instr_mask2 == 0x58)
    {
	# ANL	A, Rn			01011rrr			R0 .. R7

    print_3('anl', "A, $rn_name", "ACC &= $rn_name");
    }
  elsif ($instr_mask2 == 0x68)
    {
	# XRL	A, Rn			01101rrr			R0 .. R7

    print_3('xrl', "A, $rn_name", "ACC ^= $rn_name");
    }
  elsif ($instr_mask2 == 0x78)
    {
	# MOV	Rn, #data		01111rrr dddddddd		R0 .. R7	data

    $rb0   = sprintf "%02X", $parm0;
    $str0  = present_char($parm0);
    operation_R_reg($rn_regs, Rx_MOV, $parm0);
    print_3('mov', "$rn_name, #0x$rb0", "$rn_name = 0x$rb0$str0");
    }
  elsif ($instr_mask2 == 0x88)
    {
	# MOV	direct, Rn		10001rrr aaaaaaaa		R0 .. R7	register address

    $rb0   = regname($parm0, \$name0);
    print_3('mov', "$rb0, $rn_name", "$name0 = $rn_name");
    invalidate_DPTR_Rx();
    }
  elsif ($instr_mask2 == 0x98)
    {
	# SUBB	A, Rn			10011rrr			R0 .. R7

    print_3('subb', "A, $rn_name", "ACC -= $rn_name + CY");
    }
  elsif ($instr_mask2 == 0xA8)
    {
	# MOV	Rn, direct		10101rrr aaaaaaaa		R0 .. R7	register address

    $rb0   = regname($parm0, \$name0);
    operation_R_reg($rn_regs, Rx_INV);
    print_3('mov', "$rn_name, $rb0", "$rn_name = $name0");
    }
  elsif ($instr_mask2 == 0xB8)
    {
	# CJNE	Rn, #data, rel		10111rrr dddddddd rrrrrrrr	R0 .. R7 	data		relative address

    $addr  = $address + $instr_size + expand_offset($parm1);
    $rb0   = labelname($addr);
    $str0  = sprintf "%02X", $parm0;
    printf "cjne\t" . align("$rn_name, #0x$str0, $rb0", ALIGN_SIZE) . "; If ($rn_name != 0x$str0) then jumps hither: 0x%04X\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr_mask2 == 0xC8)
    {
	# XCH	A, Rn			11001rrr			R0 .. R7

    operation_R_reg($rn_regs, Rx_INV);
    print_3('xch', "A, $rn_name", "ACC <-> $rn_name");
    }
  elsif ($instr_mask2 == 0xD8)
    {
	# DJNZ	Rn, rel			11011rrr rrrrrrrr		R0 .. R7	relative address

    $addr  = $address + $instr_size + expand_offset($parm0);
    $rb0   = labelname($addr);
    $str0  = ($address == $addr) ? ' (waiting loop)' : '';
    printf "djnz\t" . align("$rn_name, $rb0", ALIGN_SIZE) . "; If (--$rn_name != 0) then jumps hither: 0x%04X$str0\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr_mask2 == 0xE8)
    {
	# MOV	A, Rn			11101rrr			R0 .. R7

    print_3('mov', "A, $rn_name", "ACC = $rn_name");
    }
  elsif ($instr_mask2 == 0xF8)
    {
	# MOV	Rn, A			11111rrr			R0 .. R7

    operation_R_reg($rn_regs, Rx_INV);
    print_3('mov', "$rn_name, A", "$rn_name = ACC");
    }
  elsif ($instr == 0x00)
    {
	# NOP				00000000

    print "nop\n";
    }
  elsif ($instr == 0x02)
    {
	# LJMP	addr16			00000010 aaaaaaaa aaaaaaaa	a15-a8 a7-a0	absolute address

    $addr  = ($parm0 << 8) | $parm1;
    $rb0   = labelname($addr);
    $str0  = ($address == $addr) ? ' (endless loop)' : '';
    printf "ljmp\t" . align($rb0, ALIGN_SIZE) . "; Jumps hither: 0x%04X$str0\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x03)
    {
	# RR	A			00000011

    print_3('rr', 'A', 'ACC[76543210] = ACC[07654321]');
    }
  elsif ($instr == 0x04)
    {
	# INC	A			00000100

    print_3('inc', 'A', '++ACC');
    }
  elsif ($instr == 0x05)
    {
	# INC	direct			00000101 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('inc', $rb0, "++$name0");
    invalidate_reg($parm0);
    }
  elsif ($instr == 0x10)
    {
	# JBC	bit, rel		00100000 bbbbbbbb rrrrrrrr	bit address		relative address

    $addr  = $address + $instr_size + expand_offset($parm1);
    $rb0   = bitname($parm0, \$name0);
    $rb1   = labelname($addr);
    printf "jbc\t" . align("$rb0, $rb1", ALIGN_SIZE) . "; If ($name0 == H) then $name0 = L and jumps hither: 0x%04X\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x12)
    {
	# LCALL	addr16			00010010 aaaaaaaa aaaaaaaa	a15-a8 a7-a0	absolute address

    $addr  = ($parm0 << 8) | $parm1;
    $rb0   = labelname($addr);
    $str0  = sprintf "0x%04X", $addr;
    print_3('lcall', $rb0, "Calls this: $str0 (PC += $instr_size, [++SP] = PCL, [++SP] = PCH, PC = $str0)");
    invalidate_DPTR_Rx();
    }
  elsif ($instr == 0x13)
    {
	# RRC	A			00010011

    print_3('rrc', 'A', 'ACC[76543210] = ACC[C7654321], CY = ACC[0]');
    }
  elsif ($instr == 0x14)
    {
	# DEC	A			00010100

    print_3('dec', 'A', '--ACC');
    }
  elsif ($instr == 0x15)
    {
	# DEC	direct			00010101 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('dec', $rb0, "--$name0");
    invalidate_reg($parm0);
    }
  elsif ($instr == 0x20)
    {
	# JB	bit, rel		00100000 bbbbbbbb rrrrrrrr	bit address		relative address

    $addr  = $address + $instr_size + expand_offset($parm1);
    $rb0   = bitname($parm0, \$name0);
    $rb1   = labelname($addr);
    $str0  = ($address == $addr) ? ' (waiting loop)' : '';
    printf "jb\t" . align("$rb0, $rb1", ALIGN_SIZE) . "; If ($name0 == H) then jumps hither: 0x%04X$str0\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x22)
    {
	# RET				00100010

    print_3('ret', '', "PCH = [SP--], PCL = [SP--]");
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x23)
    {
	# RL	A			00100011

    print_3('rl', 'A', 'ACC[76543210] = ACC[65432107]');
    }
  elsif ($instr == 0x24)
    {
	# ADD	A, #data		00100100 dddddddd		data

    $rb0   = sprintf "0x%02X", $parm0;
    $str0  = present_char($parm0);
    print_3('add', "A, #$rb0", "ACC += $rb0$str0");
    }
  elsif ($instr == 0x25)
    {
	# ADD	A, direct		00100101 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('add', "A, $rb0", "ACC += $name0");
    }
  elsif ($instr == 0x30)
    {
	# JNB	bit, rel		00110000 bbbbbbbb rrrrrrrr	bit address		relative address

    $addr  = $address + $instr_size + expand_offset($parm1);
    $rb0   = bitname($parm0, \$name0);
    $rb1   = labelname($addr);
    $str0  = ($address == $addr) ? ' (waiting loop)' : '';
    printf "jnb\t" . align("$rb0, $rb1", ALIGN_SIZE) . "; If ($name0 == L) then jumps hither: 0x%04X$str0\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x32)
    {
	# RETI				00110010

    print_3('reti', '', "PCH = [SP--], PCL = [SP--]");
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x33)
    {
	# RLC	A			00110011

    print_3('rlc', 'A', 'ACC[76543210] = ACC[6543210C], CY = ACC[7]');
    }
  elsif ($instr == 0x34)
    {
	# ADDC	A, #data		00110100 dddddddd		data

    $rb0   = sprintf "0x%02X", $parm0;
    $str0  = present_char($parm0);
    print_3('addc', "A, #$rb0", "ACC += $rb0 + CY$str0");
    }
  elsif ($instr == 0x35)
    {
	# ADDC	A, direct		00110101 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('addc', "A, $rb0", "ACC += $name0 + CY");
    }
  elsif ($instr == 0x40)
    {
	# JC	rel			01000000 rrrrrrrr 		relative address

    $addr  = $address + $instr_size + expand_offset($parm0);
    $rb0   = labelname($addr);
    printf "jc\t" . align($rb0, ALIGN_SIZE) . "; If (CY == H) then jumps hither: 0x%04X\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x42)
    {
	# ORL	direct, A		01000010 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('orl', "$rb0, A", "$name0 |= ACC");
    invalidate_reg($parm0);
    }
  elsif ($instr == 0x43)
    {
	# ORL	direct, #data		01000011 aaaaaaaa dddddddd	register address	data

    $rb0   = regname($parm0, \$name0);
    $rb1   = sprintf "0x%02X", $parm1;
    $str0  = present_char($parm1);
    print_3('orl', "$rb0, #$rb1", "$name0 |= $rb1$str0");
    invalidate_reg($parm0);
    }
  elsif ($instr == 0x44)
    {
	# ORL	A, #data		01000100 dddddddd		data

    $rb0   = sprintf "0x%02X", $parm0;
    $str0  = present_char($parm0);
    print_3('orl', "A, #$rb0", "ACC |= $rb0$str0");
    }
  elsif ($instr == 0x45)
    {
	# ORL	A, direct		01000101 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('orl', "A, $rb0", "ACC |= $name0");
    }
  elsif ($instr == 0x50)
    {
	# JNC	rel			01010000 rrrrrrrr 		relative address

    $addr  = $address + $instr_size + expand_offset($parm0);
    $rb0   = labelname($addr);
    printf "jnc\t" . align($rb0, ALIGN_SIZE) . "; If (CY == L) then jumps hither: 0x%04X\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x52)
    {
	# ANL	direct, A		01010010 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('anl', "$rb0, A", "$name0 &= ACC");
    invalidate_reg($parm0);
    }
  elsif ($instr == 0x53)
    {
	# ANL	direct, #data		01010011 aaaaaaaa dddddddd	register address	data

    $rb0   = regname($parm0, \$name0);
    $rb1   = sprintf "0x%02X", $parm1;
    $str0  = present_char($parm1);
    print_3('anl', "$rb0, #$rb1", "$name0 &= $rb1$str0");
    invalidate_reg($parm0);
    }
  elsif ($instr == 0x54)
    {
	# ANL	A, #data		01010100 dddddddd		data

    $rb0   = sprintf "0x%02X", $parm0;
    $str0  = present_char($parm0);
    print_3('anl', "A, #$rb0", "ACC &= $rb0$str0");
    }
  elsif ($instr == 0x55)
    {
	# ANL	A, direct		01010101 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('anl', "A, $rb0", "ACC &= $name0");
    }
  elsif ($instr == 0x60)
    {
	# JZ	rel			01100000 rrrrrrrr 		relative address

    $addr  = $address + $instr_size + expand_offset($parm0);
    $rb0   = labelname($addr);
    printf "jz\t" . align($rb0, ALIGN_SIZE) . "; If (ACC == 0) then jumps hither: 0x%04X\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x62)
    {
	# XRL	direct, A		01100010 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('xrl', "$rb0, A", "$name0 ^= ACC");
    invalidate_reg($parm0);
    }
  elsif ($instr == 0x63)
    {
	# XRL	direct, #data		01100011 aaaaaaaa dddddddd	register address	data

    $rb0   = regname($parm0, \$name0);
    $rb1   = sprintf "0x%02X", $parm1;
    $str0  = present_char($parm1);
    print_3('xrl', "$rb0, #$rb1", "$name0 |= $rb1$str0");
    invalidate_reg($parm0);
    }
  elsif ($instr == 0x64)
    {
	# XRL	A, #data		01100100 dddddddd		data

    $rb0   = sprintf "0x%02X", $parm0;
    $str0  = present_char($parm0);
    print_3('xrl', "A, #$rb0", "ACC ^= $rb0$str0");
    }
  elsif ($instr == 0x65)
    {
	# XRL	A, direct		01100101 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('xrl', "A, $rb0", "ACC |= $name0");
    }
  elsif ($instr == 0x70)
    {
	# JNZ	rel			01110000 rrrrrrrr 		relative address

    $addr  = $address + $instr_size + expand_offset($parm0);
    $rb0   = labelname($addr);
    printf "jnz\t" . align($rb0, ALIGN_SIZE) . "; If (ACC != 0) then jumps hither: 0x%04X\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x72)
    {
	# ORL	C, bit			01110010 bbbbbbbb		bit address

    $rb0   = bitname($parm0, \$name0);
    print_3('orl', "C, $rb0", "CY |= $name0");
    }
  elsif ($instr == 0x73)
    {
	# JMP	@A+DPTR			01110011

    print_3('jmp', '@A+DPTR', "Jumps hither: [DPTR + ACC]\n");
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x74)
    {
	# MOV	A, #data		01110100 dddddddd		data

    $rb0   = sprintf "0x%02X", $parm0;
    $str0  = present_char($parm0);
    print_3('mov', "A, #$rb0", "ACC = $rb0$str0");
    }
  elsif ($instr == 0x75)
    {
	# MOV	direct, #data		01110101 aaaaaaaa dddddddd	register address	data

    $rb0   = regname($parm0, \$name0);
    $rb1   = sprintf "0x%02X", $parm1;
    $str0  = '';
    $str1  = sprintf "%02X", $parm0;

    if ($parm0 == PSW)
      {
      $str0 = sprintf(" (select bank #%u)", ($parm1 >> 3) & 0x03) if (($parm1 & ~0x18) == 0x00);
      }
    else
      {
      $str0 = present_char($parm1);
      }

    print_3('mov', "$rb0, #$rb1", "$name0 = $rb1$str0");
    invalidate_reg($parm0);
    }
  elsif ($instr == 0x80)
    {
	# SJMP	rel			10000000 rrrrrrrr		relative address

    $addr  = $address + $instr_size + expand_offset($parm0);
    $rb0   = labelname($addr);
    $str0  = ($address == $addr) ? ' (endless loop)' : '';
    printf "sjmp\t" . align($rb0, ALIGN_SIZE) . "; Jumps hither: 0x%04X$str0\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0x82)
    {
	# ANL	C, bit			10000010 bbbbbbbb		bit address

    $rb0   = bitname($parm0, \$name0);
    print_3('anl', "C, $rb0", "CY &= $name0");
    }
  elsif ($instr == 0x83)
    {
	# MOVC	A, @A+PC		10000011

    print_3('movc', 'A, @A+PC', "ACC = ROM[PC + $instr_size + ACC]");
    }
  elsif ($instr == 0x84)
    {
	# DIV	AB			10000100

    print_3('div', 'AB', 'ACC = ACC / B, B = ACC % B');
    }
  elsif ($instr == 0x85)
    {
	# MOV	direct, direct		10000101 aaaaaaaa aaaaaaaa	forrás reg.	cél reg.

    $rb0   = regname($parm0, \$name0);
    $rb1   = regname($parm1, \$name1);
    print_3('mov', "$rb1, $rb0", "$name1 = $name0");
    invalidate_reg($parm0);
    }
  elsif ($instr == 0x90)
    {
	# MOV	DPTR, #data16		10010000 dddddddd dddddddd	d15-d8 d7-d0

    $addr  = ($parm0 << 8) | $parm1;
    $rb0   = sprintf "0x%04X", $addr;
    print_3('mov', "DPTR, #$rb0", "DPTR = $rb0");
    $DPTR = $addr;
    }
  elsif ($instr == 0x92)
    {
	# MOV	bit, C			10010010 bbbbbbbb		bit address

    $rb0   = bitname($parm0, \$name0);
    print_3('mov', "$rb0, C", "$name0 = CY");
    }
  elsif ($instr == 0x93)
    {
	# MOVC	A, @A+DPTR		10010011

    print_3('movc', 'A, @A+DPTR', 'ACC = ROM[DPTR + ACC]');
    }
  elsif ($instr == 0x94)
    {
	# SUBB	A, #data		10010100 dddddddd		data

    $rb0   = sprintf "0x%02X", $parm0;
    $str0  = present_char($parm0);
    print_3('subb', "A, #$rb0", "ACC -= $rb0 + CY$str0");
    }
  elsif ($instr == 0x95)
    {
	# SUBB	A, direct		10010101 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('subb', "A, $rb0", "ACC -= $name0 + CY");
    }
  elsif ($instr == 0xA0)
    {
	# ORL	C, /bit			10100000 bbbbbbbb		bit address

    $rb0   = bitname($parm0, \$name0);
    print_3('orl', "C, /$rb0", "CY = ~$name0");
    }
  elsif ($instr == 0xA2)
    {
	# MOV	C, bit			10100010 bbbbbbbb		bit address

    $rb0   = bitname($parm0, \$name0);
    print_3('mov', "C, $rb0", "CY = $name0");
    }
  elsif ($instr == 0xA3)
    {
	# INC	DPTR			10100011

    if ($DPTR != -1)
      {
      ++$DPTR;
      printf "inc\t" . align('DPTR', ALIGN_SIZE) . "; ++DPTR (0x%04X)\n", $DPTR;
      }
    else
      {
      print_3('inc', 'DPTR', '++DPTR');
      }
    }
  elsif ($instr == 0xA4)
    {
	# MUL	AB			10100100

    print_3('mul', 'AB', 'B:ACC = ACC * B');
    }
  elsif ($instr == 0xB0)
    {
	# ANL	C, /bit			10110000 bbbbbbbb		bit address

    $rb0   = bitname($parm0, \$name0);
    print_3('anl', "C, /$rb0", "CY &= ~$name0");
    }
  elsif ($instr == 0xB2)
    {
	# CPL	bit			10110010 bbbbbbbb		bit address

    $rb0   = bitname($parm0, \$name0);
    print_3('cpl', $rb0, "$name0 = ~$name0");
    }
  elsif ($instr == 0xB3)
    {
	# CPL	C			10110011

    print_3('cpl', 'C', 'CY = ~CY');
    }
  elsif ($instr == 0xB4)
    {
	# CJNE	A, #data, rel		10110100 dddddddd rrrrrrrr	data		relative address

    $addr  = $address + $instr_size + expand_offset($parm1);
    $rb0   = labelname($addr);
    $rb1   = sprintf "%02X", $parm0;
    printf "cjne\t" . align("A, #0x$rb1, $rb0", ALIGN_SIZE) . "; If (ACC != 0x$rb1) then jumps hither: 0x%04X\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0xB5)
    {
	# CJNE	A, direct, rel		10110101 aaaaaaaa rrrrrrrr	register address	relative address

    $addr  = $address + $instr_size + expand_offset($parm1);
    $rb0   = regname($parm0, \$name0);
    $rb1   = labelname($addr);
    printf "cjne\t" . align("A, $rb0, $rb1", ALIGN_SIZE) . "; If (ACC != $name0) then jumps hither: 0x%04X\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0xC0)
    {
	# PUSH	direct			11000000 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('push', $rb0, "++SP, [SP] = $name0");
    }
  elsif ($instr == 0xC2)
    {
	# CLR	bit			11000010 bbbbbbbb		bit address

    $rb0   = bitname($parm0, \$name0);
    print_3('clr', $rb0, "$name0 = L");
    }
  elsif ($instr == 0xC3)
    {
	# CLR	C			11000011

    print_3('clr', 'C', 'CY = L');
    }
  elsif ($instr == 0xC4)
    {
	# SWAP	A			11000100

    print_3('swap', 'A', 'ACC[76543210] = ACC[32107654]');
    }
  elsif ($instr == 0xC5)
    {
	# XCH	A, direct		11000101 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('xch', "A, $rb0", "ACC <-> $name0");
    invalidate_DPTR_Rx();
    }
  elsif ($instr == 0xD0)
    {
	# POP	direct			11010000 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('pop', $rb0, "$name0 = [SP], --SP");
    invalidate_reg($parm0);
    }
  elsif ($instr == 0xD2)
    {
	# SETB	bit			11010010 bbbbbbbb		bit address

    $rb0   = bitname($parm0, \$name0);
    print_3('setb', $rb0, "$name0 = H");
    }
  elsif ($instr == 0xD3)
    {
	# SETB	C			11010011

    print_3('setb', 'C', 'CY = H');
    }
  elsif ($instr == 0xD4)
    {
	# DA	A			11010100

    print_3('da', 'A', 'Decimal adjust the ACC.');
    }
  elsif ($instr == 0xD5)
    {
	# DJNZ	direct, rel		11010101 aaaaaaaa rrrrrrrr	register address	relative address

    $addr  = $address + $instr_size + expand_offset($parm1);
    $rb0   = regname($parm0, \$name0);
    $rb1   = labelname($addr);
    $str0  = ($address == $addr) ? ' (waiting loop)' : '';
    printf "djnz\t" . align("$rb0, $rb1", ALIGN_SIZE) . "; If (--$name0 != 0) then jumps hither: 0x%04X$str0\n", $addr;
    invalidate_DPTR_Rx();
    $prev_is_jump = TRUE;
    }
  elsif ($instr == 0xE0)
    {
	# MOVX	A, @DPTR		11100000

    print_3('movx', 'A, @DPTR', 'ACC = XRAM[DPTR]');
    }
  elsif ($instr == 0xE4)
    {
	# CLR	A			11100100

    print_3('clr', 'A', 'ACC = 0');
    }
  elsif ($instr == 0xE5)
    {
	# MOV	A, direct		11100101 aaaaaaaa		register address	The "MOV A, ACC" invalid instruction.

    $rb0   = regname($parm0, \$name0);
    print_3('mov', "A, $rb0", "ACC = $name0");
    }
  elsif ($instr == 0xF0)
    {
	# MOVX	@DPTR, A		11110000

    print_3('movx', '@DPTR, A', 'XRAM[DPTR] = ACC');
    }
  elsif ($instr == 0xF4)
    {
	# CPL	A			11110100

    print_3('cpl', 'A', 'ACC = ~ACC');
    }
  elsif ($instr == 0xF5)
    {
	# MOV	direct, A		11110101 aaaaaaaa		register address

    $rb0   = regname($parm0, \$name0);
    print_3('mov', "$rb0, A", "$name0 = ACC");
    invalidate_reg($parm0);
    }
  else
    {
	# The unknown instruction is actually simple embedded data in the code.

    $rb0   = sprintf "0x%02X", $instr;
    $str0  = present_char($instr);
    printf ".db\t" . align($rb0, ALIGN_SIZE) . "; 0x%04X: $rb0$str0\n", $address;
    }
  }

#-------------------------------------------------------------------------------

	#
	# Prints a label belonging to the $Address.
	#

sub print_label($)
  {
  my $Address = $_[0];
  my $label;

  if (defined($labels_by_address{$Address}))
    {
    $label = \%{$labels_by_address{$Address}};
    print "\n;$border0\n" if ($label->{TYPE} == SUB);

    printf "\n$label->{NAME}:\n\n";
    $label->{PRINTED} = TRUE;
    $prev_is_jump = FALSE;
    return TRUE;
    }

  return FALSE;
  }

################################################################################
################################################################################

	#
	# Auxiliary procedure. Adds a register to the sfrs list.
	#

sub reg_add_to_list($$)
  {
  my ($Address, $Name) = @_;

  if (! defined($sfrs_by_address{$Address}))
    {
    $sfrs_by_address{$Address} = $Name;
    }
  else
    {
    Log(sprintf("Warning, the address: 0x%03X already busy by the $sfrs_by_address{$Address} register.", $Address), 2);
    }

  $sfrs_by_names{$Name} = $Address;
  }

#-------------------------------------------------------------------------------

	#
	# Auxiliary procedure. Adds a bit to the bits list.
	#

sub bit_add_to_list($$)
  {
  my ($Address, $Name) = @_;

  if (! defined($bits_by_address{$Address}))
    {
    $bits_by_address{$Address} = $Name;
    }
  else
    {
    Log(sprintf("Warning, the address: 0x%03X already busy by the $bits_by_address{$Address} bit.", $Address), 2);
    }
  }

#-------------------------------------------------------------------------------

	#
	# Reads the sfrs and bits from the $Line.
	#

sub process_header_line($)
  {
  my $Line = $_[0];

  Log((' ' x $embed_level) . $Line, 5);

  if ($Line =~ /^#\s*include\s+["<]\s*(\S+)\s*[">]$/o)
    {
    $embed_level += 4;
    &read_header("$include_path/$1");
    $embed_level -= 4;
    }
  elsif ($Line =~ /^__sfr\s+__at\s*(?:\(\s*)?0x([[:xdigit:]]+)(?:\s*\))?\s+([\w_]+)/io)
    {
	# __sfr __at (0x80) P0 ;  /* PORT 0 */

    reg_add_to_list(hex($1), $2);
    }
  elsif ($Line =~ /^SFR\s*\(\s*([\w_]+)\s*,\s*0x([[:xdigit:]]+)\s*\)/io)
    {
	# SFR(P0, 0x80); // Port 0

    reg_add_to_list(hex($2), $1);
    }
  elsif ($Line =~ /^sfr\s+([\w_]+)\s*=\s*0x([[:xdigit:]]+)/io)
    {
	# sfr P1  = 0x90;

    reg_add_to_list(hex($2), $1);
    }
  elsif ($Line =~ /^__sbit\s+__at\s*(?:\(\s*)?0x([[:xdigit:]]+)(?:\s*\))?\s+([\w_]+)/io)
    {
	# __sbit __at (0x86) P0_6  ;

    bit_add_to_list(hex($1), $2);
    }
  elsif ($Line =~ /^SBIT\s*\(\s*([\w_]+)\s*,\s*0x([[:xdigit:]]+)\s*,\s*(\d)\s*\)/io)
    {
	# SBIT(P0_0, 0x80, 0); // Port 0 bit 0

    bit_add_to_list(hex($2) + int($3), $1);
    }
  elsif ($Line =~ /^sbit\s+([\w_]+)\s*=\s*0x([[:xdigit:]]+)/io)
    {
	# sbit P3_1 = 0xB1;

    bit_add_to_list(hex($2), $1);
    }
  elsif ($Line =~ /^sbit\s+([\w_]+)\s*=\s*([\w_]+)\s*\^\s*(\d)/io)
    {
	# sbit SM0  = SCON^7;

    my ($name, $reg, $bit) = ($1, $2, $3);

    bit_add_to_list($sfrs_by_names{$reg} + $bit, $name) if (defined($sfrs_by_names{$reg}));
    }
  }

#-------------------------------------------------------------------------------

	#
	# Reads in a MCU.h file.
	#

sub read_header($)
  {
  my $Header = $_[0];
  my ($fh, $pre_comment, $comment, $line_number);
  my $head;

  if (! open($fh, '<', $Header))
    {
    print STDERR "$PROGRAM: Could not open. -> \"$Header\"\n";
    exit(1);
    }

  $head = ' ' x $embed_level;

  Log("${head}read_header($Header) >>>>", 5);

  $comment = FALSE;
  $line_number = 1;
  while (<$fh>)
    {
    chomp;
    s/\r$//o;		# '\r'

	# Filters off the C comments.

    s/\/\*.*\*\///o;	# /* ... */
    s/\/\/.*$//o;	# // ...
    s/^\s*|\s*$//go;

    if ($_ =~ /\/\*/o)		# /*
      {
      $pre_comment = TRUE;
      s/\s*\/\*.*$//o;
      }
    elsif ($_ =~ /\*\//o)	# */
      {
      $pre_comment = FALSE;
      $comment = FALSE;
      s/^.*\*\/\s*//o;
      }

    if ($comment)
      {
      ++$line_number;
      next;
      }

    $comment = $pre_comment if ($pre_comment);

    if ($_ =~ /^\s*$/o)
      {
      ++$line_number;
      next;
      }

    run_preprocessor($Header, \&process_header_line, $_, $line_number);
    ++$line_number;
    } # while (<$fh>)

  Log("${head}<<<< read_header($Header)", 5);
  close($fh);
  }

#-------------------------------------------------------------------------------

	#
	# Among the blocks stows description of an instruction.
	#

sub add_instr_block($$)
  {
  my ($Address, $Instruction) = @_;
  my $instr_size = $instruction_sizes[$Instruction];

  if (! $instr_size)
    {
    $instr_size = 1;
    add_block($Address, BLOCK_CONST, $instr_size, BL_LABEL_NONE);
    }
  else
    {
    add_block($Address, BLOCK_INSTR, $instr_size, BL_LABEL_NONE);
    }

  return $instr_size;
  }

#-------------------------------------------------------------------------------

	#
	# Splits the program into small blocks.
	#

sub split_code_to_blocks()
  {
  my ($i, $instr, $size);
  my ($is_empty, $empty_begin);
  my ($is_const, $const_begin);

  $is_empty = FALSE;
  $is_const = FALSE;
  for ($i = 0; $i < $rom_size; )
    {
    $instr = $rom[$i];

    if ($instr != EMPTY)
      {
      if ($is_empty)
	{
	# The end of the empty section.

	$is_empty = FALSE;
	add_block($empty_begin, BLOCK_EMPTY, $i - $empty_begin, BL_LABEL_NONE);
	}

      if (is_constant($i))
	{
	if (! $is_const)
	  {
	  $const_begin = $i;
	  $is_const = TRUE;
	  }

	++$i;
	}
      else
	{
	if ($is_const)
	  {
	# The end of the constant section.

	  add_block($const_begin, BLOCK_CONST, $i - $const_begin, BL_LABEL_NONE);
	  $is_const = FALSE;
	  }

	$i += add_instr_block($i, $instr);
	}
      } # if ($instr != EMPTY)
    else
      {
      if (! $is_empty)
	{
	# The begin of the empty section.

	if ($is_const)
	  {
	# The end of the constant section.

	  add_block($const_begin, BLOCK_CONST, $i - $const_begin, BL_LABEL_NONE);
	  $is_const = FALSE;
	  }

	$empty_begin = $i;
	$is_empty = TRUE;
	}

      ++$i;
      }
    } # for ($i = 0; $i < $rom_size; )

  if ($is_const)
    {
    add_block($const_begin, BLOCK_CONST, $i - $const_begin, BL_LABEL_NONE);
    }
  elsif ($is_empty)
    {
    add_block($empty_begin, BLOCK_EMPTY, $i - $empty_begin, BL_LABEL_NONE);
    }
  }

#-------------------------------------------------------------------------------

	#
	# Finds address of branchs and procedures.
	#

sub find_labels_in_code()
  {
  foreach (sort {$a <=> $b} keys(%blocks_by_address))
    {
    my $ref = \%{$blocks_by_address{$_}};

    label_finder($ref) if ($ref->{TYPE} == BLOCK_INSTR);
    }
  }

#-------------------------------------------------------------------------------

	#
	# Prints an table of constants.
	#

sub print_constants($)
  {
  my $BlockRef = $_[0];
  my ($address, $size, $data, $i, $addr, $count);
  my @constants;

  $size = $BlockRef->{SIZE};

  return if (! $size);

  print "\n";

  $address = $BlockRef->{ADDR};
  @constants = @rom[$address .. ($address + $size - 1)];
  $i = 0;
  while (TRUE)
    {
    my $len = $size - $i;

    last if (! $len);

    $len = 8 if ($len > 8);

    printf "0x%04X\t.db\t", $address;
    $address += $len;
    while (TRUE)
      {
      my $byte = $constants[$i++];

      if ($byte < ord(' ') || $byte >= 0x7F)
	{
	$byte = sprintf "%02X ", $byte;
	}
      else
	{
	$byte = "'" . chr($byte) . "'";
	}

      print $byte;
      last if (! --$len);
      print ' ';
      }

    print "\n";
    } # while (TRUE)

  print "\n";
  }

#-------------------------------------------------------------------------------

	#
	# Disassembly contents of $blocks_by_address array.
	#

sub disassembler()
  {
  my $ref;

  $prev_is_jump = FALSE;
  invalidate_DPTR_Rx();

  foreach (sort {$a <=> $b} keys(%blocks_by_address))
    {
    $ref = \%{$blocks_by_address{$_}};

    if ($ref->{TYPE} == BLOCK_INSTR)
      {
      invalidate_DPTR_Rx() if (print_label($_));

      print "\n" if ($prev_is_jump);

      instruction_decoder($ref);
      }
    elsif ($ref->{TYPE} == BLOCK_CONST)
      {
      print_label($_);
      print_constants($ref);
      }
    elsif ($ref->{TYPE} == BLOCK_EMPTY)
      {
      printf("0x%04X: -- -- --\n", $_);
      printf("  ....  -- -- --\n0x%04X: -- -- --\n", $_ + $ref->{SIZE} - 1);
      }
    }
  }

#-------------------------------------------------------------------------------

	#
	# If there are datas in the code, it is possible that some labels will
	# be lost. This procedure prints them.
	#

sub print_hidden_labels()
  {
  foreach (sort {$a <=> $b} keys(%labels_by_address))
    {
    if (! $labels_by_address{$_}->{PRINTED})
      {
      print STDERR "The label: $labels_by_address{$_}->{NAME} is hidden!\n";
      }
    }
  }

################################################################################
################################################################################

sub usage()
  {
  print <<EOT;
Usage: $PROGRAM [options] <hex file>

    Options are:

	-r|--rom-size <size of program memory>

EOT
;
  printf "\t    Defines size of the program memory. (Default %u bytes.)\n", MCS51_ROM_SIZE;
  print <<EOT;

	--const-area <start address> <end address>

	    Designates a constant area, where data is stored happen. The option
	    may be given more times, that to select more areas at the same time.

	-I|--include <path to headers>

	    Path of the header files. (Default: $default_include_path)

	-M|--mcu <header.h>

	    Header file of the MCU.

	--map-file <file.map>

	    The map file belonging to the input hex file. (optional)

	-v <level> or --verbose <level>

	    It provides information on from the own operation.
	    Possible value of the level between 0 and 10. (default: 0)

	-h|--help

            This text.
EOT
;
  }

################################################################################
################################################################################
################################################################################

foreach (@default_paths)
  {
  if (-d $_)
    {
    $default_include_path = $_;
    last;
    }
  }

if (! @ARGV)
  {
  usage();
  exit(1);
  }

for (my $i = 0; $i < @ARGV; )
  {
  my $opt = $ARGV[$i++];

  given ($opt)
    {
    when (/^-(r|-rom-size)$/o)
      {
      param_exist($opt, $i);
      $rom_size = str2int($ARGV[$i++]);

      if ($rom_size < 1024)
	{
	printf STDERR "$PROGRAM: Code size of the MCS51 family greater than 1024 bytes!\n";
	exit(1);
	}
      elsif ($rom_size > MCS51_ROM_SIZE)
	{
	printf STDERR "$PROGRAM: Code size of the MCS51 family not greater %u bytes!\n", MCS51_ROM_SIZE;
	exit(1);
	}
      }

    when (/^--const-area$/o)
      {
      my ($start, $end);

      param_exist($opt, $i);
      $start = str2int($ARGV[$i++]);

      param_exist($opt, $i);
      $end = str2int($ARGV[$i++]);

      if ($start > $end)
	{
	my $t = $start;

	$start = $end;
	$end = $t;
	}
      elsif ($start == $end)
	{
	$start = MCS51_ROM_SIZE - 1;
	$end   = MCS51_ROM_SIZE - 1;
	}

      $const_areas_by_address{$start} = $end if ($start < $end);
      } # when (/^--const-area$/o)

    when (/^-(I|-include)$/o)
      {
      param_exist($opt, $i);
      $include_path = $ARGV[$i++];
      }

    when (/^-(M|-mcu)$/o)
      {
      param_exist($opt, $i);
      $header_file = $ARGV[$i++];
      }

    when (/^--map-file$/o)
      {
      param_exist($opt, $i);
      $map_file = $ARGV[$i++];
      }

    when (/^-(v|-verbose)$/o)
      {
      param_exist($opt, $i);
      $verbose = int($ARGV[$i++]);
      $verbose = 0 if (! defined($verbose) || $verbose < 0);
      $verbose = 10 if ($verbose > 10);
      }

    when (/^-(h|-help)$/o)
      {
      usage();
      exit(0);
      }

    default
      {
      if ($hex_file eq '')
	{
	$hex_file = $opt;
	}
      else
	{
	print STDERR "$PROGRAM: We already have the source file name.\n";
	exit(1);
	}
      }
    } # given ($opt)
  } # for (my $i = 0; $i < @ARGV; )

$include_path = $default_include_path if ($include_path eq '');

if ($hex_file eq '')
  {
  print STDERR "$PROGRAM: What do you have to disassembled?\n";
  exit(1);
  }

is_file_ok($hex_file);

if ($map_file eq '')
  {
  ($map_file) = ($hex_file =~ /^(.+)\.hex$/io);
  $map_file .= '.map';
  }

$map_file = '' if (! -e $map_file);

init_mem(0, $rom_size - 1);
read_hex($hex_file);

if ($header_file ne '')
  {
  is_file_ok("$include_path/$header_file");
  reset_preprocessor();
  $embed_level = 0;
  read_header("$include_path/$header_file");
  }

read_map_file();
fix_multi_byte_variables();
split_code_to_blocks();
find_labels_in_code();
add_names_labels();
disassembler();
print_hidden_labels() if ($verbose > 2);
