#pragma once
#include<iostream>
using namespace std;
#include<windows.h>

class FileSystemManager
{
public:
	void getDriveInfo() {
		DWORD sectorsPerCluster;
		DWORD bytesPerSector;
		DWORD numberOfFreeClusters;
		DWORD totalNumberOfClusters;

		if (GetDiskFreeSpace(L"C:\\", &sectorsPerCluster, &bytesPerSector, &numberOfFreeClusters, &totalNumberOfClusters)) {
			std::cout << "Sectors per cluster: " << sectorsPerCluster << std::endl;
			std::cout << "Bytes per sector: " << bytesPerSector << std::endl;
			std::cout << "Number of free clusters: " << numberOfFreeClusters << std::endl;
			std::cout << "Total number of clusters: " << totalNumberOfClusters << std::endl;
		}
		else {
			std::cerr << "Failed to retrieve disk information." << std::endl;
		}
	}

	
	void GetListDrivers() {
		DWORD drives = GetLogicalDrives();

		for (char driveLetter = 'A'; driveLetter <= 'Z'; ++driveLetter) {
			if (drives & 1) {
				std::cout << "Drive: " << driveLetter << ":\\" << std::endl;
			}
			drives >>= 1;
		}

	}

	void createDirectory(string folderName) {
		
		if (CreateDirectoryA(folderName.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError()) {
			std::cout << "Directory created successfully." << std::endl;
		}
		else {
			std::cerr << "Error creating directory. Error code: " << GetLastError() << std::endl;
		}
	}

	void ListFolders(const std::wstring& path) {		
		std::wstring searchPath = path;
		WIN32_FIND_DATA findFileData;
		HANDLE hFind = FindFirstFile(searchPath.c_str(), &findFileData);

		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
					if (wcscmp(findFileData.cFileName, L".") != 0 && wcscmp(findFileData.cFileName, L"..") != 0) {
						std::wcout << "Folder: " << findFileData.cFileName << std::endl;
					}
				}
			} while (FindNextFile(hFind, &findFileData) != 0);
			FindClose(hFind);
		}
		else {
			std::cerr << "Error: " << GetLastError() << std::endl;
		}
	}

	void ListFiles(const std::wstring& path) {
		WIN32_FIND_DATA findFileData;
		HANDLE hFind = FindFirstFile(path.c_str(), &findFileData);

		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				//if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_NORMAL) {
					std::wcout << findFileData.cFileName << std::endl;
				//}
			} while (FindNextFile(hFind, &findFileData) != 0);
			FindClose(hFind);
		}
	}
};

