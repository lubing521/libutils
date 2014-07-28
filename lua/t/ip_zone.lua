#!/opt/soft/base_env/openresty/luajit/bin/luajit-2.0.0-beta10
-- test.lua
-- -- the first program in every language
package.path="/usr/local/lib/lua/5.1/?.lua"
package.cpath="/usr/local/lib/lua/5.1/?.so"

require("utils_lua")
-----------------------------------------------------------------------------
------------------------------------ipzone tes-------------------------------
-----------------------------------------------------------------------------
ip_zones = utils_lua.ip_zones_load("/opt/soft/nginx/data/ip_lib.data")

zone = utils_lua.ip_zones_find(ip_zones, "1.93.0.1")
print(zone)

utils_lua.ip_zones_destroy(ip_zones)
