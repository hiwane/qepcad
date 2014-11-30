################################################
# mksysdep.pl V 0.0
# Created by Chris Brown, 20 May, 208
################################################
if ($#ARGV == 0 && ($ARGV[0] eq "-h" || $ARGV[0] eq "--help"))
{
    print "sconf/mksysdep.pl\n".
"sconf [x86linux|sparcsolaris]\n\n".
"This script installs system dependent files for\n".
"saclib.  It attempts to diagnose architecture and\n".
"processor type and install the proper files.  You\n".
"can give the arch/os type explicitly as one of the\n".
"arguments listed above, and the script will install\n".
"what you've asked for regardless of its diagnosis.\n";
    exit 0;
}

if (! $ENV{'saclib'})
{
    print "SACLIB Error: The saclib environment variable must be set!\n";
    exit(1);
}

### Get architecture type
$ptype = "unknown";
$uname = `uname -mpi`;
if ($uname =~ /i\S*86/)
{
    $ptype = "x86";
}
elsif ($uname =~ /Sun|sun|SUN|Sparc|sparc|SPARC/)
{
    $ptype = "sparc";
}
else
{
    print "SACLIB Warning: Could not determine processor type!\n";
}

### Get OS type
$ostype = "unknown";
$uname = `uname -s`;
if ($uname =~ /linux|Linux|LINUX/)
{
    $ostype = "linux";
}
elsif ($uname =~ /Sun|sun|SUN|solaris|Solaris/)
{
    $ostype = "solaris";
}
else
{
    print "SACLIB Warning: Could not determine OS type!\n";
}

### Call appropriate install script
if ($#ARGV == 1 && $ARGV[0] eq "x86linux")
{
    print "SACLIB Warning: Installing x86linux system dependent files!\n";
    system("bash -c \"pushd >/dev/null $ENV{'saclib'}/sysdep/linuxX86 ; ./install ; popd >/dev/null\"");
}
elsif ($#ARGV == 1 && $ARGV[0] eq "sparcsolaris")
{
    print "SACLIB Warning: Installing sparcsolaris system dependent files!\n";
    system("bash -c \"pushd >/dev/null $ENV{'saclib'}/sysdep/solarisSparc ; ./install ; popd >/dev/null\"");
}
elsif ($ptype eq "x86" && $ostype eq "linux")
{
    system("bash -c \"pushd >/dev/null $ENV{'saclib'}/sysdep/linuxX86 ; ./install ; popd >/dev/null\"");    
}
elsif ($ptype eq "sparc" && $ostype eq "solaris")
{
    system("bash -c \"pushd >/dev/null $ENV{'saclib'}/sysdep/solarisSparc ; ./install ; popd >/dev/null\"");
}
