<?php

/*
 * Test reporting and fixing "too much space before" errors in single line arrays.
 */
$array = array( 'b', 'd' ); // OK.
$array = array( 'a' => 'b', 'c' => 'd' ); // OK.
$array = array( 'a'    => 'b', 'c'               => 'd' ); // Bad x 2.

$array = array( 'a' /* Comment. */ => /* Comment. */ 'b' ); // OK.
$array = array( 'a' /* Comment. */    => /* Comment. */ 'b' ); // Bad.

$array = array( array( 'a' => 'b', 'c' => 'd' ) ); // OK.
$array = array( array( 'a'   => array( 'c'     => 'd' ) ) ); // Bad x 2.

/*
 * Test reporting errors and fixing double arrow alignment in a multi-line arrays.
 */
$array = array(
	'b',
	'd',
	// Something.
	'f',
);
$array = array(
	'a'   => 'b',
	'ccc' => 'd',
	'ee'  => 'f',
	'g'
		=> 'h',
);
$array = array(
	'a'   => 'b',
	123   => 'd',
	56958 => 'f',
	'g'
		=> 'h',
);

// Test no space before.
$array = array(
	'a'=> 'b', // Bad.
);
$array = array(
	'a'=> 'b', // Bad.
	'ccc'=> 'd', // Bad.
	'ee'=> 'f', // Bad.
	'g'
		=> 'h',
);

// Test too much space before.
$array = array(
	'a'        => 'b', // Bad.
);
$array = array(
	'a'             => 'b', // Bad.
	'ccc' => 'd',
	'ee'    => 'f', // Bad.
	'g'
		=> 'h',
);

// Test exact number of spaces before vs minimum.
$array = array(
	'a'     => 'b', // Bad.
	'ccc'   => 'd', // Bad.
	'ee'    => 'f', // Bad.
	'g'
		=> 'h',
);

// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment exact false
$array = array(
	'a'        => 'b',
);
$array = array(
	'a'     => 'b',
	'ccc'   => 'd',
	'ee'    => 'f',
	'g'
		=> 'h',
);
$array = array(
	'a'  => 'b', // Bad.
	'ccc' => 'd',
	'ee'    => 'f', // Bad.
	'g'
			=> 'h',
);
$array = array(
	'a'	=> 'b', // Bad - also note: uses mid-line tab.
	'ccc'   => 'd',
	'ee'    => 'f',
	'g'
		      => 'h',
);
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment exact true

// Test dealing with new lines.
$array = array(
	'a'
		=> 'b',
	'ccc'
		=> 'd',
);
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment ignoreNewline false
$array = array(
	'a'
		=> 'b', // Bad.
	'ccc'
		=> 'd', // Bad.
);
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment ignoreNewline true

// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment exact false
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment ignoreNewline false
// Test combined ignore new lines false + exact false.
$array = array(
	'a'     => 'b',
	'ccc'   => 'd',
	'ee'    => 'f',
	'g'
		=> 'h', // Bad.
);
$array = array(
	'a'  => 'b', // Bad.
	'ccc' => 'd',
	'ee'    => 'f', // Bad.
	'g'
				=> 'h', // Bad.
);
$array = array(
	'a'  => 'b', // Bad.
	'ccc' => 'd', // Bad.
	'ee'      => 'f',
	'g'
			  => 'h', // Bad.
);
$array = array(
	'a'  => 'b', // Bad.
	'ccc'   => 'd',
	'ee'    => 'f',
	'g'
		      => 'h', // Bad.
);
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment exact true
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment ignoreNewline true


/*
 * Test with maxColumn value set.
 */
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment maxColumn 12
$array = array(
	'a'   => 'b',
	'ccc' => 'd',
	'ee'  => 'f',
	'gggggggggg' => 'h',
	'i'
		=> 'j',
	'kkkkkkkkkkkk'
				 => 'l',
);
$array = array(
	'a' => 'b', // Bad.
	'ccc' => 'd',
	'ee' => 'f', // Bad.
	'gggggggggg'=> 'h', // Bad - no space before.
);
$array = array(
	'a'            => 'b', // Bad.
	'ccc'          => 'd', // Bad.
	'ee'           => 'f', // Bad.
	'gggggggggg'   => 'h', // Bad - too much space before.
);
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment maxColumn 1000

// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment exact false
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment maxColumn 12
// Test combined maxColumn value set + exact false.
$array = array(
	'a' => 'b',
);
$array = array(
	'a'    => 'b',
);
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee'   => 'f',
	'gggggggggg' => 'h',
	'i'
		=> 'j',
	'kkkkkkkkkkkk'
				 => 'l',
);

$array = array(
	'a'        => 'b', // Bad.
);
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee' => 'f', // Bad.
	'gggggggggg' => 'h',
);
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee'       => 'f', // Bad.
	'gggggggggg' => 'h',
);
$array = array(
	'a'        => 'b', // Bad.
	'ccc'      => 'd', // Bad.
	'ee'       => 'f', // Bad.
	'gggggggggg' => 'h',
);
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment exact true
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment maxColumn 1000

// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment exact false
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment maxColumn 12
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment ignoreNewline false
// Test combined maxColumn value set + exact false + ignore new lines false.
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee'   => 'f',
	'gggggggggg' => 'h',
	'i'
		=> 'j', // Bad.
	'kkkkkkkkkkkk'
				 => 'l', // Bad.
);
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee' => 'f', // Bad.
	'gggggggggg' => 'h',
	'i'
		=> 'j', // Bad.
	'kkkkkkkkkkkk'
				 => 'l', // Bad.
);
$array = array(
	'a'    => 'b',
	'ccc'  => 'd',
	'ee'       => 'f', // Bad.
	'gggggggggg'=> 'h', // Bad.
	'i'
		=> 'j', // Bad.
	'kkkkkkkkkkkk'
				 => 'l', // Bad.
);
$array = array(
	'a'        => 'b', // Bad.
	'ccc'      => 'd', // Bad.
	'ee'       => 'f', // Bad.
	'gggggggggg' => 'h',
	'i'
		=> 'j', // Bad.
	'kkkkkkkkkkkk'
				 => 'l', // Bad.
);
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment exact true
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment maxColumn 1000
// @codingStandardsChangeSetting WordPress.Arrays.MultipleStatementAlignment ignoreNewline true


// Test mixed complex arrays.
$array = array(
	'a'   => 'b', // Bad.
	12345 => 'd', // Bad.
	'f',
	'g'
		=> 'h',
		array( 'something' ),
	array( 'a' => 'something' ),
	array(
		'a' => 'something',
	),
	'i' => array( 'something' ), // Bad.
			'jjjjjj' => array( 'a' => 'something' ),
	'kk' => array( // Bad.
		'a'     => 'something', // Bad.
	),
	$ab . 'l' => array( 'a' => 'something' ), // Bad.
	// Compound multi-line key.
	$ab .
	'l' => array( 'a' => 'something' ), // Bad.
		$ab . 'l' => array( 'a' => 'something' ), // Bad.
);