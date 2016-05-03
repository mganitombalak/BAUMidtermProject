#pragma once
#include "FileManager.h"

class FileDataAdapter
{
const FileManager* fileManager;
public:
	bool IsOpen() const;
	explicit FileDataAdapter(const FileManager* const);
	~FileDataAdapter();
};

