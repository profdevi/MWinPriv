/*    
    MWinPriv.exe : Display access token privledges of the current process
    Copyright (C) 2017  Comine.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

//v1.5 copyright Comine.com 20170226U1411
#ifndef MWinAccessToken_h
#define MWinAccessToken_h

////////////////////////////////////////////////////
#include <windows.h>
#include "MStdLib.h"
#include "MString.h"

//******************************************************
//**  MWinAccessToken class
//******************************************************
class MWinAccessToken
	{
	////////////////////////////////////////////////
	void ClearObject(void);
	
	////////////////////////////////////////////////
	public:
	MWinAccessToken(bool create=false);
	~MWinAccessToken(void);
	bool Create(void);
	bool Destroy(void);
	bool AddPrivilege(const wchar_t *privledge);	// Add a privledge
	bool DelPrivilege(const wchar_t *privledge);	// Once a priv is removed, it may not be added(some os)
	bool HasPrivilege(const wchar_t *privledge);	//=true if privledge is held
	bool RemoveAllPrivileges(void);					// Remove All Privledges from current token
	bool GetOwner(MString &owner,SID_NAME_USE &usertype);		// Get Owner
	bool Print(void);								// Print Info about current access Token Privledges
	};

#endif // MWinAccessToken_h

