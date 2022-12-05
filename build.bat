ssh mrshiehx@192.168.0.108 "cd /mnt/hgfs/share/edk2/ShiehOS;make"
java project_tools.SignWriter build/kernel.elf 1
cpefi