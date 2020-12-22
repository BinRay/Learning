package main

import (
	"errors"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"github.com/jinzhu/gorm"
	"time"
)

// 模型定义，表会被默认解析为tb_view_logs，字段会被解析称小写蛇形表示法
type tbViewLog struct {
	Id             uint `gorm:"column:id; PRIMARY_KEY; autoIncrement"`
	SessionId      uint
	Ip             string
	ViewBeginTime  time.Time `gorm:"autoCreateTime"`
	ViewUpdateTime time.Time `gorm:"autoUpdateTime"`
	Site           string
}

// 新建记录
func create(db *gorm.DB) {
	viewLog := tbViewLog{
		SessionId: 3,
		Ip:        "127.0.0.2",
		ViewBeginTime: time.Now(),
		ViewUpdateTime: time.Now(),
		Site:      "letter1",
	}
	result := db.Create(&viewLog)

	fmt.Println("viewLog.Id:", viewLog.Id)
	fmt.Println("result.Error:", result.Error)
	fmt.Println("result.RowsAffected:", result.RowsAffected)
}

// 检索，获取第一条记录，同take，last
func first(db *gorm.DB) {
	var log tbViewLog
	result := db.First(&log)
	fmt.Println(log)
	fmt.Println(result)

	// 检查ErrRecordNotFound错误
	errors.Is(result.Error, gorm.ErrRecordNotFound)
}

// 检索全部对象
func find(db *gorm.DB) {
	var logs []tbViewLog
	result := db.Find(&logs)

	fmt.Println(result.RowsAffected)	// 返回找到的记录数
	fmt.Println(result.Error)
}

// 条件检索
func where(db *gorm.DB) {
	var log tbViewLog
	db.Where("id = ?", 3).Find(&log)

	fmt.Println(log)

}

func main() {

	//connectString := fmt.Sprintf("%s:%s@tcp(%s)/%s?charset=utf8mb4&parseTime=True", user, pwd, url, dbName)
	connectString := fmt.Sprintf("root:mysql-pwd@tcp(127.0.0.1)/db_cm0808?charset=utf8mb4&parseTime=True")
	db, err := gorm.Open("mysql", connectString)
	if err != nil {
		fmt.Println(err)
		return
	}

	//create(db)
	//first(db)
	//find(db)
	where(db)
	db.Clauses
}
