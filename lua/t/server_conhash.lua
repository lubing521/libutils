#!/opt/soft/base_env/openresty/luajit/bin/luajit-2.0.0-beta10
-- test.lua
-- -- the first program in every language
package.path="/opt/soft/base_env/openresty/lualib/?.lua"
package.cpath="/opt/soft/base_env/openresty/lualib/?.so"

require("utils_lua")

-----------------------------------------------------------------------------
--------------------server_conhash------------------------------------------
-----------------------------------------------------------------------------
local load_policy_file     = "/opt/soft/cdn_dispatcher/cdn_dispatcher/lua/load_server_conhash_data.lua"
local server_conhash = utils_lua.server_conhash_create(load_policy_file);
local ip = utils_lua.server_conhash_find(server_conhash, 127, "/videos/tv/xxx.ts");
if ip then 
    print(ip);
end
utils_lua.server_conhash_destroy(server_conhash);
