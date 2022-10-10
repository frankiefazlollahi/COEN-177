Step 1) Run the following commands in your host machine (Mate Terminal):
		$ setup vmware
		$ minix-get-image
		$ vmware &

Step 2) This will open the VMWare application. Go to Minix3 and start VM.

Step 3) Login as "root". Set your password with the "passwd" command.

Step 4) File Transfer:
		In the virtual machine enter: # tcpd ftp /usr/bin/in.ftpd &
		In the virtual machine enter (this will show an IP address we'll use): # ifconfig
		In the host machine enter: ftp xxx.xxx.xxx.xxx (<- your IP address from the last step)

Step 5) Run the following commands on your host machine:
		$ cd /usr/src/kernel
		$ get main.c
	This will add main.c to your host machine's home directory.
	Edit the file however you like and save the changes.
	Put this edited version back by using:
		$ put main.c

Step 6) The updated main.c should be back in the kernel folder.
	In your virtual machine enter: 
		# cd /usr/src
		# make world
	Wait for a few minutes while it remakes your kernel.
	When it is finished enter:
		# reboot
	You should see your changes you made in the reboot screen if you entered a printf statement correctly.
	
