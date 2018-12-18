# Change these variables as needed
VM_NAME="UbuntuServer"
UBUNTU_ISO_PATH=~/workplace-settings/ubuntu-18.10-desktop-amd64.iso
VM_HD_PATH="UbuntuServer.vdi" # The path to VM hard disk (to be created).
SHARED_PATH=~ # Share home directory with the VM


vboxmanage createvm --name $VM_NAME --ostype Ubuntu_64 --register
vboxmanage createhd --filename $VM_NAME.vdi --size 32768
vboxmanage storagectl $VM_NAME --name "SATA Controller" --add sata --controller IntelAHCI
vboxmanage storageattach $VM_NAME --storagectl "SATA Controller" --port 0 --device 0 --type hdd --medium $VM_HD_PATH
vboxmanage storagectl $VM_NAME --name "IDE Controller" --add ide
vboxmanage storageattach $VM_NAME --storagectl "IDE Controller" --port 0 --device 0 --type dvddrive --medium $UBUNTU_ISO_PATH
vboxmanage modifyvm $VM_NAME --ioapic on
vboxmanage modifyvm $VM_NAME --memory 1024 --vram 128
vboxmanage modifyvm $VM_NAME --nic1 nat
vboxmanage modifyvm $VM_NAME --natpf1 "guestssh,tcp,,2222,,22"
vboxmanage modifyvm $VM_NAME --natdnshostresolver1 on
vboxmanage sharedfolder add $VM_NAME --name shared --hostpath $SHARED_PATH --automount
