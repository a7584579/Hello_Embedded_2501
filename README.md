# Project name
Hello_Embedded_2501-A Smart Coffee Machine

This is a repository established by a group of interesting people to create something truly enjoyable. We are thrilled and dedicated to this little charming hand-made craft. 

The project is a smart coffee machine based on the Raspberry PI 5 to recognize images and heart rate signals, adjust the coffee formula to improve the quality of the user's mood.

## Catalogue
- [Introduction](#Introduction)
- [Working Environment](#Working_Environment)
- [Usage](#Usage)
- [Example](#Example)
- [How to contribute](#How_to_contribute)
- [Repository_Structure](#Repository_Structure)
- [Lisence](#Lisence)
- [Contacts](#Contacts)
## Introduction


## Working_Environment
Ubuntu 22.04.5 on Raspberry5 for now.
Expected to be deployed on different platform. 
## Usage 

## Example



## How_to_contribute
##### 1.Fork this repository first.
Click the Fork button to duplicate this repository to your GitHub account.
##### 2.Clone the repository to local
Use git bash to clone repository.
```bash
git clone https://github.com/a7584579/Hello_Embedded_2501.git
cd Hello_Embedded_2501
```
##### 3.Create new branch
Before you start modifying the code, create a new branch. The branch name can describe the feature you want to develop or the problem you want to fix.
```bash
git checkout -b feature       #description of function
```
##### 4.Write codes and test it
- Do code development on your branch.
- Make sure your changes don't break existing functionality, and write the necessary test cases.
- You can run the project's test script locally to verify that the changes take effect.
##### 5.Submit your codes
Please submit with detailed submission instructions that describe the changes you have made.
```bash
git add .
git commit -m "description of changes"
```
##### 6.Push it to github repository
```bash
git push origin feature #description of your push
```
##### 7.Craete Pull Request
Open your repository on GitHub, click the Compare & Pull Request button, fill in the Pull Request description, and submit the merge request. Our maintainers review and give feedback in a timely manner.

#### Notice
Code_Space:  It is utilized to place our code and some related documents. Every file and folder should be documented to clarify your structures. And Readme.md must be written for every file folder.
## Repository_Structure

	Hello_Embedded_2501
		|Documents				#Used for placing some helpful documents
		|Source					#Used for placing source codes
		|---|Image_Handle			#Source codes about Image processing
		|---|---Readme.md
		|---|Biosensor_Handle			#Source codes about geting biosensor data
		|---|---Readme.md
		|---|Screen_Handle			#Source codes for screen interaction
		|---|---Readme.md
		|---Readme.md
		|Head
		|---|Image_Handle
		|---|---Image_Handle.h
		|Tools					#Used for placingt some useful assistances
		|---|Readme.md
		|Readme.md

## Lisence
This project is licensed under the MIT License.
## Contacts
If you have any questions or suggestions, please contact a758457953@gmail.com or visit the project's GitHub page and leave your comments.
