<!DOCTYPE HTML>
<html>
<head>
<script>
   // Clears all the text in the element with ID.
	function clearElement(ID) {
			var x = document.getElementById(ID);
			x.innerHTML = " ";
		}
	
	// AppendTo(ID,TEXT) adds the text to the element with ID.
	function appendTo(ID,Text){
			var x = document.getElementById(ID);
			x.innerHTML = x.innerHTML + "<br/> - " + Text;
		}
	
	function checkForm(){ // προτεραιότητα α' έχουν οι εδώ έλεγχοι JS
	                      // λόγω του onclick στο submit    
			clearElement("problemArea");
			var x = document.getElementById('problemArea');
			x.innerHTML = "Error Messages Area:";
			
			// Each function is separately evaluated to get all errors.
			var t1 = checkEmail();
			var t2 = checkWebsite();
			var t3 = checkGender();
			return t1 && t2 && t3; 
			
		}
		
		
	function checkEmail(){
			// Gets the value
			var mail = document.forms[0].email.value;
			// Checks the value
		
			// email must have the characters uom . 
			if (mail.length != 0)
				if (mail.indexOf('uom') == -1) 
				  {appendTo("problemArea","Please, insert a 'uom' email."); return false;}
			
			return true;
		}
		
	function checkWebsite()
		{
			// Gets the value
			var site = document.forms[0].website.value;
			// Checks the value
		
			// website must have the characters gr. 
			if (site.length != 0)
			  if (site.indexOf('gr') == -1)  
				{appendTo("problemArea","Please, insert a 'gr' website."); return false;}		
			return true;
		}
		function checkGender()
		{
			var i;
			for (i=0;i<2;i++)
			{
				if (document.forms[0].gender[i].checked) {return true;}
			}
			
			appendTo("problemArea","Please, select a gender.");
			return false;
		}
   </script>
<style>
.error {color: #FF0000;
       }
div#problemArea {border:solid 2px red; margin:7px; 
			padding:5px;
			background-color:#000000;
			color: white;
			float:right;
			width:40%;
		} 
</style>
</head>
<body>

<?php
// define variables and set to empty values
$nameErr = $emailErr = $genderErr = $websiteErr = "";
$name = $email = $gender = $comment = $website = "";


/* προτεραιότητα τελευταία, έχουν οι εδώ έλεγχοι, αφού αυτοί γίνονται από τον server μετά την υποβολή των στοιχείων
*/
if ($_SERVER["REQUEST_METHOD"] == "POST") {
   if (empty($_POST["name"])) {   
     $nameErr = "Name is required"; /* το μήνυμα σφάλματος αυτό δεν θα 
	                                  εμφανιστεί: η ιδιότητα required
                                      στην ετικέτα του πεδίου name αφήνει
									  στον browser να κάνει τον έλεγχο
									  εγκυρότητας και δεν επιτρέπει ο browser
									  αποστολή κενού name στον server.
									  Οπότε αν υπάρχει το required, δεν πρέπει
									  και ο server να κάνει άσκοπα τον ίδιο έλεγχο.
								*/ 
   } else {
     $name = test_input($_POST["name"]);
     // check if name only contains letters and whitespace
     if (!preg_match("/^[a-zA-Z ]*$/",$name)) {
       $nameErr = "Only letters and white space allowed";
     }
   }
  
   if (empty($_POST["email"])) {
     $emailErr = "Email is required"; /* το μήνυμα σφάλματος αυτό δεν θα 
	                                  εμφανιστεί: η ιδιότητα required
                                      στην ετικέτα του πεδίου email αφήνει
									  στον browser να κάνει τον έλεγχο
									  εγκυρότητας και δεν επιτρέπει ο browser
									  αποστολή κενού email στον server.
									  Οπότε αν υπάρχει το required, δεν πρέπει
									  και ο server να κάνει άσκοπα τον ίδιο έλεγχο.
								*/ 
   } else {
     $email = test_input($_POST["email"]);
     // check if e-mail address is well-formed
     if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
       $emailErr = "Invalid email format";
     }
   }
    
   if (empty($_POST["website"])) {
     $website = "";
   } else {
     $website = test_input($_POST["website"]);
     // check if URL address syntax is valid (this regular expression also allows dashes in the URL)
     if (!preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i",$website)) {
       $websiteErr = "Invalid URL";
     }
   }

   if (empty($_POST["comment"])) {
     $comment = "";
   } else {
     $comment = test_input($_POST["comment"]);
   }

   if (empty($_POST["gender"])) {
     $genderErr = "Gender is required";  /* το μήνυμα σφάλματος αυτό δεν θα 
	                                  εμφανιστεί: η JS συνάρτηση checkGender
                                      αφήνει στον browser να κάνει τον έλεγχο
									  εγκυρότητας και δεν επιτρέπει ο browser
									  αποστολή κενού gender στον server.
									  Οπότε αν υπάρχει η JS συνάρτηση, δεν πρέπει και ο server να κάνει άσκοπα τον ίδιο έλεγχο.
								*/
   } else {
     $gender = test_input($_POST["gender"]);
   }
}

function test_input($data) {
   $data = trim($data);
   $data = stripslashes($data);
   $data = htmlspecialchars($data);
   return $data;
}
?>

<h2>PHP Form Validation Example</h2>
<p><span class="error">* required field.</span></p>
<div id="problemArea"> Error Messages Area: <br/></div>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
   Name: <input type="text" name="name" value="<?php echo $name;?>" required>
   <!-- προτεραιότητα β' έχουν οι εδώ έλεγχοι από τα attribues στις ετικέτες  -->
   <span class="error">* <?php echo $nameErr;?></span>
   <br><br>
   E-mail: <input type="text" name="email" value="<?php echo $email;?>" required>
   <span class="error">* <?php echo $emailErr;?></span>
   <br><br>
   Website: <input type="text" name="website" value="<?php echo $website;?>">
   <span class="error"><?php echo $websiteErr;?></span>
   <br><br>
   Comment: <textarea name="comment" rows="5" cols="40"><?php echo $comment;?></textarea>
   <br><br>
   Gender:
   <input type="radio" name="gender" <?php if (isset($gender) && $gender=="female") echo "checked";?>  value="female" >Female
   <input type="radio" name="gender" <?php if (isset($gender) && $gender=="male") echo "checked";?>  value="male" >Male
   <span class="error">* <?php echo $genderErr;?></span>
   <br><br>
   <input type="submit" name="submit" value="Submit" onclick="return checkForm();">
</form>


<?php
echo "<h2>Your Input:</h2>";
echo $name;  // μόνο αφού γίνει η υποβολή θα εμφανιστούν οι τιμές των input
echo "<br>";
echo $email;
echo "<br>";
echo $website;
echo "<br>";
echo $comment;
echo "<br>";
echo $gender;
?>

</body>
</html>