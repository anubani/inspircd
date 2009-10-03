#!/usr/bin/perl
use strict;
use warnings;
BEGIN { push @INC, $ENV{SOURCEPATH}; }
use make::configure;

chdir $ENV{BUILDPATH};

my $out = shift;
my $verbose;

if ($out =~ /^-/) {
	$_ = $out;
	$out = shift;
	$verbose = /v/;
}

my $file = shift;

my $cflags = $ENV{CXXFLAGS};
$cflags =~ s/ -pedantic// if nopedantic($file);
$cflags .= ' ' . getcompilerflags($file);

my $flags;
if ($out =~ /\.so$/) {
	$flags = join ' ', $cflags, $ENV{PICLDFLAGS}, getlinkerflags($file);
} else {
	$flags = "$cflags -c";
}

my $execstr = "$ENV{RUNCC} $flags -o $out $file";
print "$execstr\n" if $verbose;
exec $execstr;
exit 1;