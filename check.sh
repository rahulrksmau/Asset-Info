#!/bin/bash
# sudo apt-get install ./your-package.deb 
# sudo apt-get -f install
# package and it's dependencies will all installed


Check=`dpkg-query -l | grep libcurl`
if [ -z "$Check" ]
then
	echo $Check
else
	echo $Check
fi

