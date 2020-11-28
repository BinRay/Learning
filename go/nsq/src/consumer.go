package main

import (
	"fmt"
	"time"
)
import "github.com/nsqio/go-nsq"

type Consumer struct{}

// 处理接收到的信息（实现nsq.Handler）
func ( *Consumer ) HandleMessage( msq *nsq.Message ) error {
	fmt.Println( "Receive from ", msq.NSQDAddress, ":", string(msq.Body) )
	return nil
}

func main() {
	cfg := nsq.NewConfig()
	cfg.LookupdPollInterval = time.Second

	consumer, err := nsq.NewConsumer( "nsqtest", "test-channel", cfg )

	if err != nil {
		panic( err )
	}

	consumer.SetLogger( nil, 0 )
	consumer.AddHandler( &Consumer{} )

	err = consumer.ConnectToNSQD( "122.51.55.53:4150" )

	if err != nil{
		panic( nil )
	}

	for {
		time.Sleep( time.Second )
	}

	consumer.Stop()
}
