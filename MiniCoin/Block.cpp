#include "Block.h"
#include <string>
#include <time.h>
#include "sha256.h"
#include <iostream>
using namespace std;

bool Block::validateBlock(Block toValidate) {
	string realHash = sha256(to_string(toValidate.nonce) + to_string(toValidate.index) + to_string(toValidate.timeStamp) + toValidate.sender + toValidate.receiver + to_string(toValidate.amount) + toValidate.previousHash);
	if (realHash == toValidate.hash) {
		return true;
	}
	return false;
}

Block::Block(int index, string sender, string receiver, double amount, string previousHash) {
	this->index = index;
	this->sender = sender;
	this->receiver = receiver;
	this->amount = amount;
	this->previousHash = previousHash;
	// will be set during mining
	timeStamp = 0;
	nonce = 0;
	hash = "";
	minerAddress = "";
}

int Block::mineBlock(string minerAddress) {
	this->minerAddress = minerAddress;
	timeStamp = time(NULL);

	// set everything up
	nonce = 0;
	string preHash = "";
	string postHash = "random";

	// loop through and hash, changing the nonce value by one until we find a hash with '0000' at the start
	for (; postHash[0] != '0' || postHash[1] != '0' || postHash[2] != '0' || postHash[3] != '0'; nonce++) {
		preHash = to_string(nonce) + to_string(index) + to_string(timeStamp) + sender + receiver + to_string(amount) + previousHash;
		postHash = sha256(preHash);
	}

	this->hash = postHash;
	return nonce;
}




int Block::getIndex() const {
	return index;
}

int Block::getNonce() const {
	return nonce;
}

string Block::getSender() const {
	return sender;
}

string Block::getReceiver() const {
	return receiver;
}
double Block::getAmount() const {
	return amount;
}
string Block::getHash() const {
	return hash;
}
string Block::getMiner() const {
	return minerAddress;
}