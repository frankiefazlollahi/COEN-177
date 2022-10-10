1.) Run commands to open VMWare application:
	setup vmware
	minix-get-image
	vmware &

2.) Go to Minix3 and start VM

3.) Login as root and with password (optional)

4.) Enter the following commands in your virtual machine:
	tcpd ftp /usr/bin/in.ftpd &
	ifconfig (this will give you the IP address to use next)

5.) Enter the following in your host machine:
	ftp xxx.xxx.xxx.xxx (the IP address you just got)

6.) Now you have set up the ftp server. Run the following commands on your host machine:
	cd /usr/src/kernel
	get proc.c
    This will put the proc.c file in your host machine's home directory.
    In the proc.c file, edit the pick_proc() function to add a random chance (for example 20% of the time) to skip the current priority level
    Save your changes and enter the command:
	put proc.c
    Now you have put the edited file back and it should be back in the kernel folder.

7.) Now in your virtual machine enter:
	cd /usr/src
	make world (this will remake your kernel with the changes)

8.) If you type the command "reboot" you should notice that it takes longer for minix to start up than before.
