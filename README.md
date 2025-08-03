## How To Use

package_extract_file("volprompt", "/tmp/volprompt");
run_program("/system/bin/chmod", "0755", "/tmp/volprompt");
ui_print("###########################################");
ui_print("# QUESTION? YES/NO #");
ui_print("# Press Volume-Up = YES, Volume-Down = NO #");
ui_print("###########################################");
if (run_program("/tmp/volprompt") == 0) then
  ui_print("#");
	ui_print("#");
	ui_print("#################################################");
	ui_print("#    You chose YES - +++++++++++++++++++++++!   #");
	ui_print("#             +++++++++++++++++++++!            #");
  ui_print("# +++++++++++++++++++++++++++++++++++++++++++++ #");
	ui_print("#################################################");
	package_extract_file("++++++++.img", "/dev/block/by-name/+++++++_a");
	package_extract_file("++++++++.img", "/dev/block/by-name/+++++++_b");
 else
  ui_print("#");
	ui_print("#");
	ui_print("##########################################");
	ui_print("#              You chose NO              #");
	ui_print("# ++++++++++++++++++++++++++++++++++++++ #");
	ui_print("##########################################");
