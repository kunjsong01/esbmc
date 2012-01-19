#!/bin/sh

stat .git > /dev/null 2>/dev/null
if test $? != 0; then
  echo "Please run gensignatures.sh in the root dir of ESBMC"
  exit 1
fi

tgzlist=`ls .release/*.tgz`

date=`date`
echo "Signatures for ESBMC binaries, version $1 ($date)"
echo ""

# Generate checksums of each tgz
for file in $tgzlist;
do
  md5sum=`md5sum $file | cut "--delim= " -f 1`
  shasum=`shasum $file | cut "--delim= " -f 1`
  sha2sum=`sha256sum $file | cut "--delim= " -f 1`

  basename=`basename $file`
  echo "File $basename checksums:"
  echo "MD5:    $md5sum"
  echo "SHA:    $shasum"
  echo "SHA256: $sha2sum"
  echo ""
done
