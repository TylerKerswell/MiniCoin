#pragma once
#include <time.h>
#include <string>
using namespace std;


/// This class represents a single block in the blockchain, it is mostly used to store data of a singular block.
/// 
/// 
/// The data in an object of this class should look something like this:
/// 
///   block = {
/// 
///    'index': <index in the chain> int,
/// 
///    'timestamp': <unix_timestamp> time_t,
/// 
///    'nonce': <number to get 0000 in front of hash> int,s
/// 
///    'transaction':
/// 
///		'sender': <sender address in hexidecimal> string
/// 
///		'receiver': <receiver address hexidecimal> string
/// 
///		'amount': <amount to send> double
/// 
///    'previous_hash': <hash previous block in hex> str,
/// 
///    'hash': <this blocks hash in hex> str,
/// 
///		'minerAddress': <address of the miners account> str,
/// 
///}
/// 
/// MiniCoin will not use merkle trees in its implementation.

class Block {

public:

	/// <summary>
	/// This function is used to validate a particular block to check if it is valid.
	/// </summary>
	/// <param name="toValidate">Block to be validated.</param>
	/// <returns>True if the inputted block's hash matches the hash value of the block.</returns>
	static bool validateBlock(Block toValidate);

	/// <summary>
	/// Makes a block from the given inputs.
	/// </summary>
	/// <param name="index">index that this block will have on the chain</param>
	/// <param name="sender">address of the sender of this transaction</param>
	/// <param name="receiver">address of the receiver</param>
	/// <param name="amount">amount to send</param>
	/// <param name="previousHash">hash of previous block in the chain</param>
	Block(int index, string sender, string receiver, double amount, string previousHash);

	/// <summary>
	/// this function mines the current block and produces a nonce value and 
	/// </summary>
	/// <param name="minerAddress">the address of the person mining this block</param>
	/// <returns>nonce value</returns>
	int mineBlock(string minerAddress);

	int getIndex() const;
	int getNonce() const;
	string getSender() const;
	string getReceiver() const;
	double getAmount() const;
	string getHash() const;
	string getMiner() const;

private:
	unsigned int index;
	long timeStamp;
	unsigned int nonce;
	string sender;
	string receiver;
	double amount;
	string previousHash;
	string hash;
	string minerAddress;
};