<?php

// OK.
if ($a === 123) {
} elseif ($a == 123) {
} elseif ($a !== 123) {
} elseif ($a != 123) {}

function abc( $a = 'default' ) {}
if (in_array( $a, array( 1 => 'a', 2 => 'b' ) ) ) {}

switch ( $a === $b ) {}
switch ( true ) {
	case $sample == 'something':
		break;
}

for ( $i = 0; $i == 100; $i++ ) {}
for ( $i = 0; $i >= 100; $i++ ) {}
for ( $i = 0; ; $i++ ) {}
for (;;) {}

do {
} while ( $sample == false );

while ( $sample === false ) {}

// Assignments in condition.
if ($a = 123) {
} elseif ($a = 'abc') {
} else if( $a += 10 ) {
} else if($a -= 10) {
} else if($a *= 10) {
} else if($a **= 10) {
} else if($a /= 10) {
} else if($a .= strtolower($b)) {
} else if($a %= SOME_CONSTANT) {
} else if($a &= 2) {
} else if($a |= 2) {
} else if($a ^= 2) {
} else if($a <<= 2) {
} else if($a >>= 2) {
} else if($a ??= $b) {
} elseif( $a = 'abc' && $b = 'def' ) {
} elseif(
    $a = 'abc'
	&& $a .= 'def'
) {}

if ($a[] = 123) {
} elseif ($a['something'] = 123) {
} elseif (self::$a = 123) {
} elseif (parent::$a *= 123) {
} elseif (static::$a = 123) {
} elseif (MyClass::$a .= 'abc') {
} else if( $this->something += 10 ) {}

switch ( $a = $b ) {}
switch ( true ) {
	case $sample = 'something':
		break;

	case $sample = 'something' && $a = $b:
		break;
}

for ( $i = 0; $i = 100; $i++ ) {}
for ( $i = 0; $i = 100 && $b = false; $i++ ) {}

do {
} while ( $sample = false );

while ( $sample = false ) {}

if ($a = 123) :
endif;

// Non-variable assignment found.
if (123 = $a) {}
if (strtolower($b) = $b) {}
if (array( 1 => 'a', 2 => 'b' ) = $b) {}

if (SOME_CONSTANT = 123) {
} else if(self::SOME_CONSTANT -= 10) {}

if ( $a() = 123 ) {
} else if ( $b->something() = 123 ) {
} elseif ( $c::something() = 123 ) {}

switch ( true ) {
	case 'something' = $sample:
		break;
}

while (list($field_name, $file_names) = each($formfiles)) {}

/*
 * Ternaries should also be checked, but can only be reliably done when in parenthesis.
 */

// OK.
$mode = ( $a == 'something' ) ? 'on' : 'off';
$mode = ( $a == 'on' ? 'true' : $a == 'off' ? 't' : 'f' );

// Bad.
$mode = ( $a = 'on' ) ? 'on' : 'off';
$mode = ( $a = 'on' ) ?: 'off';
$mode = ( $a = 'on' ) ? 'true' : ( $a = 'off' ) ? 't' : 'f'; // Bad x 2.
$mode = ( $a = 'on' ? 'on' : 'off' );
$mode = ( $a = 'on' ?: 'off' );
$mode = ( $a = 'on' ? 'true' : ( $a = 'off' ? 't' : 'f' ) ); // Bad x 2.
$mode = ( $a = 'on' ? 'true' : $a = 'off' ? 't' : 'f' ); // Bad x 3. The first ? triggers 1, the second (correctly) 2.

// Currently not checked.
$mode = $a = 'on' ? 'on' : 'off';
$mode = $a = 'on' ?: 'off';
$mode = $a = 'on' ? 'true' : $a = 'off' ? 't' : 'f';
