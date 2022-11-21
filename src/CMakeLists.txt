target_sources(blowfish PRIVATE
	"main.cpp"
)

add_subdirectory(exception)
add_subdirectory(interpreting)
add_subdirectory(lexing)
add_subdirectory(parsing)
add_subdirectory(statements)
add_subdirectory(tokens)