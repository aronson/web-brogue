define([
    "jquery",
    "underscore",
    "backbone",
    "dataIO/send-generic",
    "models/auth"
], function ($, _, Backbone, send) {
    
    var PlayView = Backbone.View.extend({
        el: "#play",
        
        events: {
            "click #brogue-1-7-4" : "startBrogue"
        },
        startBrogue: function(event){
            event.preventDefault();
            
            send("brogue", "start");
            this.goToConsole();
        },
        
        goToConsole : function(){
            $('header').addClass("inactive");
            $("#lobby").addClass("inactive");
            $("#console").removeClass("inactive").focus();
        },
        
        goToLobby: function(){
            $('header').removeClass("inactive");
            $("#lobby").removeClass("inactive");
            $("#console").addClass("inactive");
        }
    });
    
    return PlayView;
    
});