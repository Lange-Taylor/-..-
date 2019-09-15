#pragma once 

#include <cstdlib>
#include <cstdio>
#include <mysql/mysql.h>
#include <json/json.h>
namespace  image_system
{
  static MYSQL* MySQLInit()
  {

    // 使用mysql API 来操作数据库
    // 1.创建一个mysql操作句柄
    MYSQL* mysql = mysql_init(NULL);
    // 2.拿着句柄和数据库建立连接
    if(mysql_real_connect(mysql, "127.0.0.1", "root", "", "image_system", 3306,NULL, 0) == NULL)
    {
      //数据库连接失败
      printf("数据库连接失败！%s\n", mysql_error(mysql));
      return NULL;
    }
    //3.设置编码格式
    mysql_set_character_set(mysql,"utf8");
    return mysql;
  }
  static void MySQLRelease(MYSQL* mysql)
  {
    mysql_close(mysql);
  }


  //操作数据库中的 image_table 表
  //使用JSON封装函数参数（MySQL参数过多）


  class ImageTable
  {
  public:
    ImageTable(MYSQL* mysql):mysql_(mysql) {}

    //使用JOSN的原因：1.扩展更方便 2. 方便和服务器接收到的数据打通
    bool Insert(const Json::Value& image)
    {
      char sql[4*1024] = {0};
      sprintf(sql,"insert into image_table values(null,'%s','%s','%s','%s','%s','%d')",
          image["image_name"].asCString(),image["type"].asCString(),image["md5"].asCString(),
          image["path"].asCString(),image["upload_time"].asCString(),image["size"].asInt());
      printf("[Insert sql] %s\n", sql);

      int ret = mysql_query(mysql_, sql);
      if (ret != 0)
      {
        printf("Insert 执行 SQL 失败! %s\n", mysql_error(mysql_));
        return false;
      }
      return true;
    }

    bool SelectAll(Json::Value* images)
    {
      char sql[4*1024] = {0};
      sprintf(sql, "select * from image_table");
      int ret = mysql_query(mysql_, sql);
      if(ret != 0)
      {
        printf("SelectAll 执行 SQL 失败！%s\n", mysql_error(mysql_));
        return false;
      }
       //遍历结果集合，并把结果集写到images 参数中
       MYSQL_RES* result = mysql_store_result(mysql_);
       
       int rows = mysql_num_rows(result);
       for (int i = 0; i < rows; ++i) 
       {
         MYSQL_ROW row = mysql_fetch_row(result);
         //数据库查出的每条记录都相当于是一个图片的信息
         //需要把这个信息转换为JOSN格式
       
         Json::Value image;
         image["image_id"] = atoi(row[0]);
         image["image_name"] = row[1];
         image["content_type"] = row[2];
         image["md5"] = row[3];
         image["path"] = row[4];
         image["upload_time"] = row[5];
         image["size"] = atoi(row[6]);
         images->append(image);
       }
       //忘了会导致内存泄漏
       mysql_free_result(result);
       return true;
    }

    bool SelectOne(int image_id, Json::Value* image_ptr)
    {
      
      char sql[4*1024] = {0};
      sprintf(sql, "select * from image_table where image_id = %d", image_id);
      int ret = mysql_query(mysql_, sql);
      if(ret != 0)
      {
        printf("SelectOne 执行 SQL 失败！%s\n", mysql_error(mysql_));
        return false;
      }
      MYSQL_RES* result = mysql_store_result(mysql_);
      int rows = mysql_num_rows(result);
      if (rows != 1) {
        printf("SelectOne 查找结果不为 1 条!实际查到 rows = %d!\n", rows);
        return false;

      }
      MYSQL_ROW row = mysql_fetch_row(result); 
      Json::Value image;
      image["image_id"] = atoi(row[0]);
      image["image_name"] = row[1];
      image["content_type"] = row[2];
      image["md5"] = row[3];
      image["path"] = row[4];
      image["upload_time"] = row[5];
      image["size"] = atoi(row[6]);
      *image_ptr = image;

      //
      mysql_free_result(result);
      return true;
   }

    bool Delete(int image_id)
    {
      char sql[1024 * 4] = {0};
      sprintf(sql, "delete from image_table where image_id=%d", image_id);
      int ret = mysql_query(mysql_, sql);
      if (ret != 0) {
        printf("执行 sql 失败! sql=%s, %s\n", sql, mysql_error(mysql_));
        return false;

      }
      return true;
    }
  private:
    MYSQL* mysql_;
  };
} //end image_system
