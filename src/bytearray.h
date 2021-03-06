/**
 * (n+1)Sec Multiparty Off-the-Record Messaging library
 * Copyright (C) 2016, eQualit.ie
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of version 3 of the GNU Lesser General
 * Public License as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef SRC_BYTEARRAY_H_
#define SRC_BYTEARRAY_H_

#include <cstdint>
#include <cstring>
#include <string>

namespace np1sec
{

template<int n> struct ByteArray
{
	uint8_t buffer[n];
	
	ByteArray() {}
	explicit ByteArray(const uint8_t* data)
	{
		memcpy(buffer, data, n);
	}
	
	std::string as_string() const
	{
		return std::string(reinterpret_cast<const char*>(buffer), n);
	}
	
	std::string dump_hex() const
	{
		const char* hex_digits = "0123456789abcdef";
		std::string output;
		for (size_t i = 0; i < sizeof(buffer); i++) {
			if (i > 0) {
				output += ':';
			}
			output += hex_digits[(buffer[i] >> 4) & 0x0f];
			output += hex_digits[(buffer[i] >> 0) & 0x0f];
		}
		return output;
	}
	
	bool operator==(const ByteArray<n>& other) const
	{
		return memcmp(buffer, other.buffer, n) == 0;
	}
	
	bool operator!=(const ByteArray<n>& other) const
	{
		return memcmp(buffer, other.buffer, n) != 0;
	}
	
	bool operator<(const ByteArray<n>& other) const
	{
		return memcmp(buffer, other.buffer, n) < 0;
	}
	
	bool operator>(const ByteArray<n>& other) const
	{
		return memcmp(buffer, other.buffer, n) > 0;
	}
	
	bool operator<=(const ByteArray<n>& other) const
	{
		return memcmp(buffer, other.buffer, n) <= 0;
	}
	
	bool operator>=(const ByteArray<n>& other) const
	{
		return memcmp(buffer, other.buffer, n) >= 0;
	}
};

}

#endif
