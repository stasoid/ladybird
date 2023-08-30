/*
 * Copyright (c) 2023, Sam Atkins <atkinssj@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/ByteString.h>
#include <AK/StringView.h>
#if defined(AK_OS_WINDOWS)
typedef struct _WIN32_FIND_DATAA WIN32_FIND_DATA;
#else
#    include <dirent.h>
#endif

namespace Core {

struct DirectoryEntry {
    enum class Type {
        BlockDevice,
        CharacterDevice,
        Directory,
        File,
        NamedPipe,
        Socket,
        SymbolicLink,
        Unknown,
        Whiteout,
    };
    Type type;
    // FIXME: Once we have a special Path string class, use that.
    ByteString name;
#if !defined(AK_OS_WINDOWS)
    ino_t inode_number;

    static StringView posix_name_from_directory_entry_type(Type);
    static StringView representative_name_from_directory_entry_type(Type);
    static Type directory_entry_type_from_stat(mode_t st_mode);
    static DirectoryEntry from_dirent(dirent const&);
    static DirectoryEntry from_stat(DIR*, dirent const&);
#else
    static DirectoryEntry from_find_data(WIN32_FIND_DATA const&);
#endif
};

}
