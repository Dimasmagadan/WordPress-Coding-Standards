<?php

	function exampleFunctionA() {} // OK: [tab].

/*
 * OK: [tab][space][space][space][space].
 * The four spaces will be replaced by a tab by the upstream sniff.
 */
	    function exampleFunctionB() {}

/*
 * OK: [tab][space][space][tab][space][tab].
 * The space replacement here will be handled by the upstream sniff.
 */
	  	 	function exampleFunctionC() {}

	/**
	 * OK: Doc comments are indented with tabs and one space.
	 *
	  * @var string  <= Bad.
	 * @access private
	 */

	/*
	 * OK: Multi-line comments are indented with tabs and one space.
	 *
	   * <= Bad.
	 */

	 function exampleFunctionD() {} // Bad: [tab][space].
	  function exampleFunctionE() {} // Bad: [tab][space][space].
	   function exampleFunctionF() {} // Bad: [tab][space][space][space].

	 function exampleFunctionG() {} // WPCS: precision alignment ok.

?>

	<p>
	  Bad: Some text with precision alignment.
	</p>

<?php

// Testing empty line within a comment.
/*

*/
