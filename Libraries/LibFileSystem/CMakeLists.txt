set(SOURCES
#    FileSystem.cpp
#    TempFile.cpp
dummy.cpp
)

serenity_lib(LibFileSystem filesystem)
target_link_libraries(LibFileSystem PRIVATE LibCoreMinimal)
