#!/bin/bash

pkg="system-asset.deb"
sudo dpkg -i $pkg
sudo apt-get -f install 

echo "System-asset installation done . "
