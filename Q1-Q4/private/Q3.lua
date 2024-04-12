
function do_sth_with_PlayerParty(playerId, membername)
    local player = Player(playerId)
    local party = player:getParty()
 
    for k, v in pairs(party:getMembers()) do 
        if (v == membername) then 
            party:removeMember(k)
        end
    end
end
