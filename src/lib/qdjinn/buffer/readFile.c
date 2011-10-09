/*****************************************************************************
 *  Quoha - a quaint framework for static websites
 *
 *  Copyright (C) 2011 Michael D Henderson
 *
 *  This file is part of Quoha (http://quoha.org).
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

/*****************************************************************************
 */
#include "local.h"
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>

/*****************************************************************************
 * return 0 if able to read entire file
 *        1 if error reading file
 */
int QBufferReadFile(int fd, size_t bytesToRead, unsigned char *buf) {
	ssize_t totalBytesRead = 0;
	while (bytesToRead > 0) {
		ssize_t bytesRead = read(fd, buf, bytesToRead);
		if (bytesRead == -1 && errno == EINTR) {
			continue;
		} else if (bytesRead <= 0) {
			// assume the worst
			return 1;
		}
		bytesToRead    -= bytesRead;
		buf            += bytesRead;
		totalBytesRead += bytesRead;
	}

	return 0;
}
