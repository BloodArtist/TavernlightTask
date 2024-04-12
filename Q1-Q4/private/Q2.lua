
function printSmallGuildNames(memberCount)
    -- This method prints names of all guilds that have less than memberCount max members
    local selectGuildQuery = "SELECT name FROM guilds WHERE max_members < %d;"
    local resultId = db.storeQuery(string.format(selectGuildQuery, memberCount))
    
    if (resultId ~= nil) then
        while(not result.next(resultId))
            local guildName = result.getString("name")
            print(guildName)
        end
        
        -- Free resultId 
        result.free(resultId) 
    else
        print("No guilds found with less than " .. memberCount .. " members.")
    end
end