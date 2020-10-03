new node 
	-> initialize cryptographic params
	-> set state to expecting messages
	-> while no events occur:
		EXPECTING
		On event: Internal Message (a.k.a somebody votes on this exact 'station')
			\-> prepare block entry 
			\-> change state to TRANSMIT 
			\-> transmit entry
		On event: Receive 
				(Note: Receive a BLOCK! Not a single entry!)
			\-> change state to BUSY(?) 
			\-> check if the block is verified
				|-> Yes? Check whether this block is already in the chain
							|-> Yes? Update yours.
							|-> No? Add it to your chain.
				|-> No? Perform the 'Am-I-The-Chosen-One-Algorithm'
							|-> Yes? Do you accept? 
										|-> Yes? Change state and start mining.
										|-> No? Then you don't mine.
											(Note: That's because in the interval of time between being accepted in the mining pool and the time of actually receiving the block that's to be mined you may have become busy.)
											(NoteNote: busy is actually the state BUSY)
							|-> No? Add it to your chain.
					(Note: 'DRY')
			\-> Go back to EXPECTING
	
block header from given initialized message pool 
		(Note: The number of zeroes to mine for)
	-> FLAGS |= NOT_VERIFIED
	-> transmit the block looking for somebody to mine it 

new block header WITHOUT the given initialized message pool:
	-> set previous to 0
		(Note: This should be initialized to a "real" value after it has been transmitted; then it would get different previous block hashes)
	-> set hash to 0
		(Note: This should be initialized to a "real" value after its contents are filled and a hashing algorithm to each one can be applied)
	-> set nonce to minimum value 
	-> generate random number in some range as a PRIVATE FIELD

the am-i-the-chosen-one-algorithm:
	-> calculate what percentage of the CPU is busy w/ receiving and transmitting
	-> if percentage is not too high:
		(Note: What is too high?)
			\-> Yes? Then the answer is no - you are not the chosen one.
			\-> No? Then you are a candidate for the mining pool.

the mining pool:
	-> here we keep the unique id's of some devices that are available 
		for the process of mining.
	 		(Note: Let's say the count of such devices is 10.)

blocks per device:
	-> Each block's structure is the following:
		\-> A header containing the metadata of the block
		\-> A 'message pool' in which the actual block entries are stores.
			|-> Each entry contains:
					- the actual MSG
					- the digital signature
					- timestamp (the time of block creating)
					- some flags (VALID, INVALID, NOT_VERIFIED, etc.)  
	-> each block contains: 256 entries
	-> each device holds 128 blocks in its FLASH 
			(Note: These are marked 'storage slots')
	-> each device holds 16 blocks in its RAM
			(Note: These are marked 'working slots')

register an internal message:
	(Note: Such message is a vote done in this exact device)
	-> Soem 

mine:
	-> if (Flags & VERIFIED) return
	-> Look through each message and verify it through w/ the
		verification function in the cryptography interface
	-> when found -> TRANSMIT the VERIFIED version of the BLOCK
