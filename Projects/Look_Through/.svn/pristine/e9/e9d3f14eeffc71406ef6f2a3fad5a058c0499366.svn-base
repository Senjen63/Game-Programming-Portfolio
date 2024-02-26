/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Assignment 3
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "GraphicsBufferManager.h"

GraphicsBufferManager::GraphicsBufferManager()
{
	
}

GraphicsBufferManager::~GraphicsBufferManager()
{
	for (auto& buffer : mlbuffer)
	{
		delete mlbuffer[buffer.first];
	}
	clear();
}

void GraphicsBufferManager::addGraphicsBuffer(string target, GraphicsBuffer* buff)
{
	mlbuffer[target] = buff;
}

void GraphicsBufferManager::deleteGraphicBuffer(string key)
{
	mlbuffer.erase(key);
}

GraphicsBuffer* GraphicsBufferManager::getGraphicsBuffer(string key)
{
	return mlbuffer[key];
}

void GraphicsBufferManager::clear()
{
	mlbuffer.clear();
}