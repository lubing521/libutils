#!/opt/soft/base_env/openresty/luajit/bin/luajit-2.0.0-beta10

-- 解密
package.path="/opt/soft/base_env/openresty/lualib/?.lua"
package.cpath="/opt/soft/base_env/openresty/lualib/?.so"
local utils = require("utils_lua")

src="31f43ac188afbeab"
print("待解密字字符串:" .. src)
data = utils.decrypt_des3(src, "12345678")
print("解密后：" .. data)

-- 加密
time = os.time()
print("待加密内容：" .. time)
mi = utils.encrypt_des3(time,"123")
print("加密后：" .. mi)


-- time token
print("以时间作为待加密数据")
token = utils.gen_time_token_des3("123")
print("时间token：" .. token)
