/*
** 2002 January 15
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
*************************************************************************
** This file implements a simple standalone program used to test whether
** or not the SQLite library is threadsafe.
**
** Testing the thread safety of SQLite is difficult because there are very
** few places in the code that are even potentially unsafe, and those
** places execute for very short periods of time.  So even if the library
** is compiled with its mutexes disabled, it is likely to work correctly
** in a multi-threaded program most of the time.  
*/
#include "sqlite.h"
