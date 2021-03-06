/**
* Copyright (c) 2018 Zilliqa 
* This source code is being disclosed to you solely for the purpose of your participation in 
* testing Zilliqa. You may view, compile and run the code for that purpose and pursuant to 
* the protocols and algorithms that are programmed into, and intended by, the code. You may 
* not do anything else with the code without express permission from Zilliqa Research Pte. Ltd., 
* including modifying or publishing the code (or any part of it), and developing or forming 
* another public or private blockchain network. This source code is provided ‘as is’ and no 
* warranties are given as to title or non-infringement, merchantability or fitness for purpose 
* and, to the extent permitted by law, all liability for your use of the code is disclaimed. 
* Some programs in this code are governed by the GNU General Public License v3.0 (available at 
* https://www.gnu.org/licenses/gpl-3.0.en.html) (‘GPLv3’). The programs that are governed by 
* GPLv3.0 are those programs that are located in the folders src/depends and tests/depends 
* and which include a reference to GPLv3 in their program files.
**/

#include "libUtils/JoinableFunction.h"
#include "libUtils/Logger.h"

using namespace std;

void test()
{
    LOG_MARKER();
    LOG_MESSAGE("Hello world");
}

int main()
{
    // Write to a file
    INIT_FILE_LOGGER("test1");
    vector<unsigned char> bytestream = { 0x12, 0x34, 0x56, 0x78, 0x9A };

    LOG_MESSAGE("Hello world");
    LOG_PAYLOAD("Hello world", bytestream, Logger::MAX_BYTES_TO_DISPLAY); // use default max payload length
    LOG_PAYLOAD("Hello world", bytestream, 5); // use max payload length = payload length
    LOG_PAYLOAD("Hello world", bytestream, 4); // use max payload length < payload length

    // Try in different thread
    JoinableFunction(1, test);

    return 0;
}