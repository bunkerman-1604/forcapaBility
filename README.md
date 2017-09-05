# forcapaBility
mobile auto test tool appium

#geckodriver
https://github.com/mozilla/geckodriver/releases

#jmeter http header replace

#!/bin/bash
hold=LT-IMEI
cp superMan.jmx tmp.jmx
sed -i "/${hold}</,+1d" tmp.jmx
sed -i "/${hold}\"/,+a##################<stringProp name=\"Header.value\">\${${hold}_jmeter}</stringProp>" tmp.jmx
sed -i "/${hold}\"/,+a##################<stringProp name=\"Header.name\">${hold}</stringProp>" tmp.jmx
sed -i "s|##################|                  |g" tmp.jmx
