package main

import (
	"fmt"
	"log"
	"net/http"
	"strings"
)

func sayhello(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()

	fmt.Println(r.Form)
	//fmt.Println("path", r.URL.Path)
	//fmt.Println("scheme", r.URL.Scheme)
	//fmt.Println(r.Form["url_long"])

	for k, v := range r.Form{
		fmt.Println("key: ", k)
		fmt.Println("val: ", strings.Join(v, " "))
	}

	fmt.Fprintf(w, "Hello Binray~")
}

func main() {
	http.HandleFunc("/", sayhello)	// 设置路由访问，将sayhello转换为默认的headler接口，内含ServerHTTP方法
	err := http.ListenAndServe(":9090", nil)	// 设置监听端口，handler设置为空，默认获取handler = DefaultServeMux

	if err != nil {
		log.Fatal("ListenAndServe:", err)
	}


}
