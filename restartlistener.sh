#this script runs as a cron job. it checks if the tcp listener is running and if not it starts it.

if ps -A | grep  AwsDataReceiver
then
	echo "found"
else
	(exec "/home/rkasumba/tcplistener/AwsDataReceiver")
	echo "Time: $(date). Listener found off. It's been restarted." >> /home/rkasumba/tcplistener/listenerfailure.log
fi
