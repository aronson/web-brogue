var path = require('path');

var config = {
    CLIENT_DIR : path.normalize(__dirname + "/../client/"),
    BROGUE_PATH : path.normalize(__dirname + "/../brogue/bin/brogue"),
    GAME_DATA_DIR : path.normalize(__dirname + "/../game-data/"),
    db : {
        url : "mongodb://localhost/brogue"
    },
    LOBBY_UPDATE_INTERVAL : 1000
};

module.exports = config;