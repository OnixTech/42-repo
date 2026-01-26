*This project has been as part of the 42 curriculum by lupetill*

## Description
Welcome to Born2beroot project! The main task of this project is to create a virtual machine by choosing betweeon Debian or Rocky operative systems, understanding their differences, and learning how to configur them while introducing essencial Linux administration concepts.

### Debian vs Rocky

Debian is an open-source Linux operating system, free to use and supported by an independent community. It is also more flexible and user-friendly than Rocky.

Rocky Linux is a community-driven clone of Red Hat Enterprise Linux. It is focused on enterprise environments and provides a free and open-source platform with long-term support. It is mainly designed for servers and data centers, without including many tools for regular users.

I chose Debian because it is more flexible for working with different services and applications, offering more possibilities for various use cases.

### Partitioning

I am using LVM partitions to allow flexible resizing and efficient management of disk space:

```bash
sda 30G disk
├─sda1 476M part /boot
└─sda5 29.5G part
  └─sda5_crypt 29.5G crypt
    ├─LVMGroup-root 9.3G lvm /
    ├─LVMGroup-swap 2.1G lvm [SWAP]
    ├─LVMGroup-home 4.7G lvm /home
    ├─LVMGroup-var 2.8G lvm /var
    ├─LVMGroup-srv 2.8G lvm /srv
    ├─LVMGroup-tmp 2.8G lvm /tmp
    └─LVMGroup-var--log 3.7G lvm /var/log

```

## Security Policies

### Password Policy

The system enforces a strong password policy with the following rules:

- Minimum length: 10 characters
- At least one uppercase letter
- At least one lowercase letter
- At least one digit
- Maximum of 3 repeated characters
- Username cannot be used as password
- New password must differ from the previous one by at least 7 characters
- Policy is enforced for the root user

These rules are configured using PAM and system security files.

### Sudo Rules

Sudo access is restricted to authorized users only.

The following rules are applied:

- Authentication attempts are limited to 3
- A custom error message is displayed on failed login
- All sudo commands are logged
- Input and output logging is enabled
- Logs are stored in `/var/log/sudo`
- Sudo access is restricted to terminal sessions
- A secure execution path is enforced

The following settings are applied:

- Maximum password age: 30 days
- Minimum password age: 2 days
- Warning period before expiration: 7 days

## User Management

User accounts and groups are managed to control system access.

- Create user: `sudo adduser username`
- Delete user: `sudo userdel -r username`
- Create group: `sudo groupadd groupname`
- Add user to group: `sudo usermod -aG groupname username`
- Grant sudo access: `sudo usermod -aG sudo username`
- List users: `cut -d: -f1 /etc/passwd`

## Services

The following services are configured and managed on the system.

### SSH

- Check status: `sudo systemctl status ssh`
- Restart: `sudo systemctl restart ssh`

### Firewall (UFW)

- Enable: `sudo ufw enable`
- Status: `sudo ufw status`
- Allow SSH: `sudo ufw allow ssh`

## Apt vs Aptitude

APT is the default and recommended package manager for Debian systems.

Aptitude provides advanced dependency resolution and an interactive interface, but is less commonly used today.

This project uses APT for simplicity and reliability.

## AppArmor vs SELinux

AppArmor and SELinux are security systems used to control application permissions.

AppArmor is easier to configure and uses profile-based rules.
SELinux provides stronger security but is more complex to manage.

Debian mainly uses AppArmor by default, while Rocky Linux uses SELinux.

## UFW vs Firewalld

UFW and Firewalld are tools used to manage firewall rules.

UFW is simple and user-friendly, mainly used on Debian-based systems.
Firewalld is more advanced and commonly used on Red Hat-based systems.

This project uses UFW for easier firewall management.

## VirtualBox vs UTM

VirtualBox and UTM are virtualization tools used to run virtual machines.

VirtualBox is widely used and supports many operating systems.
UTM is optimized for macOS and Apple Silicon devices.

This project was developed using VirtualBox/UTM for virtualization.

## Instructions

### Getting Started

1. Import the virtual machine into Oracle Virtualbox.
2. Start the virtual machine.
3. Wait for the login promt.

### Login

Use the following credentials to acces the system:

- Username: lupetill
- Password: xxxxxxxx

## Resources

- AI tools were used to format the README and clarify technical concepts.
- GitHub repositories were used as references.
- Debian documentation and Linux man pages were consulted.
