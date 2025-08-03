## How To Use

package_extract_file("volprompt", "/tmp/volprompt");

run_program("/system/bin/chmod", "0755", "/tmp/volprompt");

if (run_program("/tmp/volprompt") == 0) then

else
