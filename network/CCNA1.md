# 路由器

## 路由器的配置

```
命令行模式下的 Route>  代表以用户模式(基本啥也干不了)
输入 enable 进入特权模式 Route#(该模式下主要用于测试和查询)  命令可按tab键补全
输入 config 进入全局配置模式Route(config)大部分的配置都要在全局模式下配置
输入 
	   interface f0/0
     interface gigabitEthernet0/0/0(路由器不一样 接口写法不一样)
进入快速以太网口
配置ip地址
		ip address 192.168.31.1 255.255.255.0
		no shutdown  打开接口
返回上一级 exit
直接回到特权模式 end

查询ip地址(特权模式下)  show running-config  
										 show ip interface brief
配置用户名(特权模式下)  hostname r1

给用户进特权模式时设置密码    enable password 123   (密码可在show running-config中看到)
													enable secret 123     (密码不能在show running-config中看到)
	
关闭域名解析  no ip domain lookup
打开域名解析  ip domain lookup
```



