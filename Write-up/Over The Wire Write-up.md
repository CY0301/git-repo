> Link to access overthewire
> ssh [bandit@bandit.labs.overthewire.org](mailto:bandit@bandit.labs.overthewire.org) -p 2220

### [[Useful Website for OverTheWire Write-up]]

--- 

## Bandit0
![[Pasted image 20230721093619.png]]
* After ssh with bandit0 and password bandit0, I used **ls** command and saw a *readme* file.
* I used **cat** command to see info in *readme* file, and it shows a line of character. 
> NH2SXQwcBdpmTEzi3bvBHMM9H66vVXjL

---

## Bandit1
![[Pasted image 20230721093745.png]]
* In bandit1, I used **ls** command and saw a file named *-*. 
* I used **./** and followed the filename and successfully open the file.
> rRGizSaX8Mk1RTb1CNQoXTcYZWU6lgzi

---

## Bandit2
![[Pasted image 20230721093853.png]]
* I used **ls** command and saw the file named with *spaces*. 
* So, when I cat the file, I used back slash at behind of the file before the spaces. 
* But we also can first type spaces then press “Tab” to let it finish by itself, it’s extremely useful. 
> aBZ0W5EmUfAf7kHTQeOwd8bauFJ2lAiG

---

## Bandit3
![[Pasted image 20230721094614.png]]
* The questions said the password stored inside the *inhere* folder. 
* After **cd** in, I used **ls -a** to see all files including hidden file. 
* Then I **cat** to get the password. 
> 2EW7BBsr6aMMoJ2HjW067dm8EgX26xNe

---

## Bandit4
![[Pasted image 20230721094759.png]]
![[Pasted image 20230721094803.png]]
* Its not a good idea to check them one by one, but luckily there just 10 files, I probably should use find command.

> Up: Found a new solution, using **file** to check the info of the file. 
> Then star symbol is to check all 
> lrIWWI6bB37kxfiCQZqUdOIYfr6eEeqR

---

## Bandit5
![[Pasted image 20230721095130.png]]
![[Pasted image 20230721095136.png]]
* Used **ls** command and saw too much of directory in it
* I got a hint from the question, it said maybe can use find command, and I went to google and someone said man the find. 
* After searching, I used **find** command with **-readable** to filter out *human-readable* file, **-size 1033c** to find the file size with *1033 bytes*. And I got a file named *-file2*.
![[Pasted image 20230721095347.png]]
* And I got a long line of human-readable characters. 
* In case it’s wrong I opened another file
![[Pasted image 20230721095415.png]]
* And it’s not readable…So *-file2* will be storing password.
> P4L4vucdmLnm8I7Vl7jG1ApGSfjYKqJU

---

## Bandit6
![[Pasted image 20230721095501.png]]
* After using series of **ls** commands, there’s no file or directory to do. 
* After doing some research on ([OverTheWire — Bandit Wargames : All Level Walkthroughs (As of July 2019) | by nwrzd | Medium](https://nwrzd.medium.com/overthewire-bandit-wargames-all-level-walkthroughs-as-of-july-2019-f80f35900454)
* I got this command. **/** after find is to let find command *search the entire file system from root*. **2>/dev/null** is to prevent ‘permission denied” error display in the screen.
![[Pasted image 20230721095757.png]]
> z7WtoNQU2XfjmMtWA8u5rN4vzqu4v99S

---
## Bandit7
![[Pasted image 20230721095824.png]]
* Used **ls – l** to check the *size of the text file*. Used **grep** to know the password
> TESKZC0XvTetK0S9xNwm25STk5iWrBvP

---
## Bandit8
![[Pasted image 20230721095940.png]]
* Using **sort** command to *sort data.txt*, and **uniq -c** command to *count the repeated lines*.
* Then used **grep “1”** to get that have 1. 
![[Pasted image 20230721100155.png]]
* But we need to have a space behind the 1, **grep “1 “** to ensure it’s 1 but not everything that contain 1.
> EN632PlfYiZbn3PhVK3XOGSlNInNE00t

---

## Bandit9
![[Pasted image 20230721100402.png]]
* Used **strings** command to *show the data*, and **grep** to *filter with several “=”.* 
> G7w8LIi6J3kTb8A7j9LgrywtEUlyyp6s

---

## Bandit10
![[Pasted image 20230721100538.png]]
* Usually, *Base64* encrypt will include *double equal sign at the last of the cipher text*.
![[Pasted image 20230721100617.png]]
* Use [CyberChef](https://cyberchef.org/#input=R3VyIGNuZmZqYmVxIHZmIFdJQU9PU0Z6TWpYWEJDMEtvU0tCYko4cHVRbTVsSUVp) to decrypt the cipher text to plain text.
> 6zPeziLdR2RKNdNYFNb6nVCKzphlXHBM

---

## Bandit11
![[Pasted image 20230721100716.png]]
* *ROT13* encrypt is to change the *first 13 alphabets to last 13 alphabets*.
![[Pasted image 20230721100757.png]]
> JVNBBFSmZwKKOP0XbFXOoW8chDz5yVRv

---

## Bandit12
![[Pasted image 20230721100826.png]]
* According to the question, first create temporary folder for the data.txt by using **mkdir**, then copy **cp** the file to the folder created.
* **xxd** *creates hex dump or converts it back to binary form*. Used **xxd -r (file to convert) > (converted location)**. 
![[Pasted image 20230721101023.png]]
* Checked the file type of file decompressed by **xxd**, its *gzip*, used **gunzip -c (file to decompressed) > (file destination)** to decompress the file, 
* **-c** is to *write the standard output, and keep the file unchanged*.
![[Pasted image 20230721101206.png]]
*file02* is *bzip2*, used **bunzip2 -c (file to decompressed) > (file destination)** and checked *file03* is *gzip*, 
similar to the previous step, got *file04*. *file04* is *tar*.
![[Pasted image 20230721101338.png]]
* Used **tar -xf (file to decompressed)** to decompress the file, but without the destination, the destination fille will automatically out, 
* **-xf** is to *extract the tar file*. 
* Similar to a *file04*, *data5.bin* uses the similar command to get *data6.bin*, and it’s *bzip2*.
![[Pasted image 20230721101541.png]]
* Used the similar command to get *file07* from *data6.bin*, and *data8.bin* from *file07*. 
* When **gunzip -c data8.bin** will get the final result, which is the password for bandit13.
> wbWdlBxEir4CaE8LaPhauuOo6pwRmrDw

---

## Bandit13
![[Pasted image 20230721101710.png]]
* Used **ssh** and *public key* provided to connect bandit14 without password. 
* **-i** is to select a file from which the identity (private key) for public key authentication is read. 
* Then add **sshkey.private** which is the public key provided. 
* And typed **bandit14@localhost** to log in to bandit14 as localhost. 
* But not successful, so I went to another website and found out to use original login method, which is **(bandit14@bandit.labs.overthewire.org -p 2220)** as it said I was attempting to log in as port 22 (ssh), but not their own port. (?)
![[Pasted image 20230721102109.png]]

---

## Bandit14
![[Pasted image 20230721102124.png]]
* We know that the password is stored in **/etc/bandit_pass/**, for **bandit14** just use command above and netcat **nc** the question required, then will get the password.
> jN2kgmIXJ6fShzhT2avhotn4Zcka6tnt

---

## Bandit15
![[Pasted image 20230721102239.png]]
* Enter command above to connect by **openssl**, then will get the password.
> JQttfApK4SeyHwDlI9SXGR50qclOAil1

---

## Bandit16
![[Pasted image 20230721102330.png]]
* First used **nmap** to *scan for open ports*, 
* **-sV** is to *do a service/version detection scan in localhost* and *specify the ports* with **-p**.
* Then got 5 open ports, the one we need is *ssl*, but *31518 and 31790* are 2 provide ssl, but *31518 only supports echo*, we I chose 31790.
![[Pasted image 20230721102516.png]]
* Used the similar command and will get the *RSA private key*. **cat /etc/bandit_pass/bandit16 | openssl s_client -connect localhost:31790 -ign_eof**, and get the RSA private key.
* Then, **mkdir /tmp/tmp_key/sshkey17.txt**, save the key to *sshkey17.txt*, and *change the file permissions to only readable*, which is **chmod 400 sshkey17.txt**.
* Lastly, use **ssh bandit17@bandit.labs.overthewire.org -p 2220 -i /tmp/tmp_key/sshkey17.txt** to get through bandit17.
> VwOSWtCA7lRKkTfbr2IDh6awj9RNZM5e

---

## Bandit17
![[Pasted image 20230721102800.png]]
* Used **diff** command to *find the difference between two files*, 
* **-q** is just *showing the brief*, 
* *-c* shows the columns.

---

## Bandit18
![[Pasted image 20230721102915.png]]
* After entering password to enter bandit18 as usual, *Byebye !* message pop out and kick me out, this is because *.bashrc* file had been modified. 
* So, I did some research and found out to use ssh as normal then put command behind it.
![[Pasted image 20230721103046.png]]
> awhqfNnAbc1naukrpqDYcF95h7HoMTrC

---

## Bandit19
![[Pasted image 20230721103135.png]]
* Red color file is *setuid* file, as the question, run the file with cat password,
![[Pasted image 20230721103217.png]]
* The bandit20 shows when running file, it will run as bandit20
> VxCazJaVykI6W36BkBU0mJTCM8rR95XT

---

## Bandit20
[OverTheWire: Level Goal: Bandit Level 20 → Level 21](https://overthewire.org/wargames/bandit/bandit21.html)
