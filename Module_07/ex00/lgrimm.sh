#!/bin/bash

# Check if the class name was provided
if [ "$#" -ne 1 ]; then
	echo "Usage: $0 <ClassName>"
	exit 1
fi

CLASS_NAME=$1
CLASS_NAME_UPPER=$(echo "$CLASS_NAME" | tr '[:lower:]' '[:upper:]')
CLASS_NAME_LOWER=$(echo "$CLASS_NAME" | tr '[:upper:]' '[:lower:]')

# Define the paths for the header and source directories
HEADER_DIR="incl"
SOURCE_DIR="src"

# Check for the header directory and create it if it does not exist
if [ ! -d "$HEADER_DIR" ]; then
	mkdir "$HEADER_DIR"
	echo "Created directory: $HEADER_DIR"
fi

# Check for the source directory and create it if it does not exist
if [ ! -d "$SOURCE_DIR" ]; then
	mkdir "$SOURCE_DIR"
	echo "Created directory: $SOURCE_DIR"
fi

HPP_FILE="$HEADER_DIR/${CLASS_NAME}.hpp"
CPP_FILE="$SOURCE_DIR/${CLASS_NAME}.cpp"

HPP_FILE="${HEADER_DIR}/${CLASS_NAME}.hpp"
CPP_FILE="${SOURCE_DIR}/${CLASS_NAME}.cpp"

# Create the .hpp file
cat <<EOT > $HPP_FILE
#ifndef ${CLASS_NAME_UPPER}_HPP
#define ${CLASS_NAME_UPPER}_HPP

#include <iostream>

class	$CLASS_NAME
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		$CLASS_NAME();
		~$CLASS_NAME();
		$CLASS_NAME(const $CLASS_NAME &$CLASS_NAME_LOWER);

		/* ------------------- METHODS --------------------- */

		/* ------------------- SETTERS --------------------- */

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		$CLASS_NAME	&operator=(const $CLASS_NAME &$origin);

	protected:
	
	private:

};

std::ostream	&operator<<(std::ostream &stream, $CLASS_NAME const &$CLASS_NAME_LOWER);

#endif // ${CLASS_NAME}_HPP
EOT

# Create the .cpp file
cat <<EOT > $CPP_FILE
#include "${CLASS_NAME}.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

$CLASS_NAME::$CLASS_NAME() { }

$CLASS_NAME::~$CLASS_NAME() { }

$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME &$CLASS_NAME_LOWER) { *this = $CLASS_NAME_LOWER; }

/* ----------------------------- METHODS ------------------------------- */

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

/* ---------------------------- OVERLOADS ------------------------------ */


$CLASS_NAME		&$CLASS_NAME::operator=(const $CLASS_NAME &origin)
{
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, $CLASS_NAME const &$CLASS_NAME_LOWER)
{
	stream << /* add here */ std::endl;
	return (stream);
}

EOT

echo "Created $HPP_FILE and $CPP_FILE for the class $CLASS_NAME."
