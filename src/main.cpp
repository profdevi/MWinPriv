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

//v1.0 copyright Comine.com 20170226U1718
#include "MStdLib.h"
#include "MCommandArg.h"
#include "MWinAccessToken.h"
#include "MLicenseGPL.h"


//******************************************************
//* Module Elements
//******************************************************
static const char *GApplicationName="MWinPriv";	// Used in Help
static const char *GApplicationVersion="1.0";	// Used in Help

////////////////////////////////////////////////////
static void GDisplayHelp(void);

////////////////////////////////////////////////////
int main(int argn,const char *argv[])
	{
	MCommandArg args(argn,argv);

	if(args.CheckRemoveHelp()==true)
		{
		GDisplayHelp();
		return 0;
		}

	if(args.CheckRemoveArg("-gpl")==true)
		{
		MLicenseGPL gpl(true);
		gpl.Print();
		return 0;
		}

	MWinAccessToken accesstoken;
	if(accesstoken.Create()==false)
		{
		MStdPrintf("**Unable to init MWinAccessToken\n");
		return 1;
		}

	accesstoken.Print();
	MStdPrintf("\n");
	return 0;
	}


////////////////////////////////////////////////////
static void GDisplayHelp(void)
	{
	MStdPrintf(	"\n"
				"   usage:  %s [-?|-gpl]\n"
				"           v%s copyright Comine.com\n"
				"\n"
				"   Program displays the Security privledges of the access token of\n"
				"   the current process"
				"\n"
				,GApplicationName,GApplicationVersion);
	}



