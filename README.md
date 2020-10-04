# ChaingeVote 

### HackTUES-6 
#### Introduction
_So let's begin_ 

Hello, fellow stranger! Welcome to the home page of our latest project.
This project originated to compete in the yearly students hackaton HackTUES. 
So let's describe its basic goals and core functionalities.

#### What is this about?
_The Problem_ 

Each voting, election, poll and such can be altered with the standard ways 
they are realised. This is specifically true for elections of national scale 
where elections can be altered.
The ability to share, express and get your opinion a proper feedback is a 
right that many don't have. And that is the goal we are aiming at. 


--------------------------
#### How to solve it?
_The Solution_ 

How 'ChaingeVote' solves this? Well, BLOCKCHAIN.
What's blockchain? You should check [this](https://en.wikipedia.org/wiki/Blockchain).

OK, now let's take a closer look at the specific solution we provide.

A Peer-to-peer network connecting _stations_ which are used to vote. These votes
are stored on blocks that are chained together. After filling a block, it gets
broadcasted to the near stations which get the block and put it in their chains.

OK, but how do we know these blocks aren't corrupted? Well, to approach this problem
we used a verification system based on complex cryptographic algorithms which provide
unique digital signatures. Based on them it is made sure that no messages (votes) 
have been duplicated. Using TCP connection and additional checksums the blocks are
authenticated.

This is short description of a complex system.
 

--------------------------
#### What's more to add?
_The advancement_

1. **Full transparency**
> During the elections the votes are published to live user-friendly applications.
*Note:* We do not gather ANY information about the individual. Nothing else but 
		the message (vote) is exptected as an input from the person.

2. **Credibility**
> Establish a trustful system where no suspicious operations are included 
in the process ; i.e. justify the term 'full transparency' by verifying
that the code we have open-sourced is the code actually running on the 
stations.

These are the most important things which should be included in another
updated and expanded version of the current state of the system.

--------------------------
#### FAQ
_Soo, about ..._ 

1. **A:** How do you suggest to implement the _second_ point from the previous part?

   **B:** An expansion to the system which provides live-calculated checksums of the
   			code running on the micro-controller. They can be compared to the ones
			calculated from the open code repository.

==============================

2. **A:** How do you solve the problem with verifying blocks from the chain when
		the system is implemented on a small micro-controllers?
		
   **B:** The common approach for block verification is using the *proof-of-work*	
		algorithm. We howeever use *proof-of-stake*. A set of stations is chosen
		randomly. Each of them is asked whether they are busy w/ any jobs at the
		moment. If not they are assigned the task to calculate the block hash and
		thus verify it. With this solution stations without many jobs (such as in 
		small towns compared to the big cities) do most of the mining and other
		provide and distribute the contents.

--------------------------
#### Contacts
_Business enquiries_ 

[Zahary Momchilov](https://github.com/ZaharyMomchilov)

_Contact info_:
	> zaharymomchilov@gmail.com
	
[Kamen Stefanov](https://github.com/kamenstefanov03)

_Contact info_:
	> kamenstefanov03@gmail.com

[Stefan Bosev](https://github.com/StefanBosev)

_Contact info_:
	> stefan.bosev1@gmail.com

[Kristiyan Stoimenov](https://github.com/boki1)

_Contact info_:
	> kristoimenov@gmail.com


