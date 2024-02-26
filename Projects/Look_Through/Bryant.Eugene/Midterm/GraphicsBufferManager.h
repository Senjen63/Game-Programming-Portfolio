/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>
#include "Trackable.h"
#include "GraphicsBuffer.h"

using namespace std;


class GraphicsBufferManager : public Trackable
{
private:
	unordered_map <string, GraphicsBuffer*> mlbuffer;
public:
	GraphicsBufferManager();
	~GraphicsBufferManager();


	void addGraphicsBuffer(string target, GraphicsBuffer* buff);
	void deleteGraphicBuffer(string key);
	GraphicsBuffer* getGraphicsBuffer(string key);
	void clear();
};