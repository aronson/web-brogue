// Full high scores view

define([
    "jquery",
    "underscore",
    "backbone",
    "dispatcher",
    "config",
    "views/score-table-cells",
    "variantLookup"
], function ($, _, Backbone, dispatcher, config, TableCells, variantLookup) {

    var AllScoresView = Backbone.View.extend({
        el: '#all-scores',
        headingTemplate: _.template($('#all-scores-heading').html()),

        events: {
            "click #all-scores-user" : "selectUserScores",
            "click #all-scores-daily" : "selectDailyScores",
            "click #all-scores-options-list" : "selectAllScoresOptions"
        },

        initialize: function() {
            this.listenTo(this.model, "add", this.render);
            this.listenTo(this.model, "change", this.render);

            this.grid = new Backgrid.Grid({
                columns: [
                    {
                        name: "username",
                        label: "Player",
                        cell: "string",
                        sortable: true,
                        editable: false
                    }, {
                        name: "prettyDate",
                        label: "Date",
                        cell: "string",
                        sortable: true,
                        editable: false
                    }, {
                        name: "seed",
                        label: "Seed",
                        cell: "string",
                        sortable: true,
                        editable: false
                    }, {
                        name: "prettySeeded",
                        label: "Seeded",
                        cell: "string",
                        sortable: false,
                        editable: false
                    }, {
                        name: "prettyVariant",
                        label: "Version",
                        cell: "string",
                        sortable: true,
                        editable: false
                    }, {
                        name: "score",
                        label: "Score",
                        cell: "integer",
                        sortable: true,
                        editable: false
                    }, {
                        name: "level",
                        label: "Level",
                        cell: TableCells.levelCell,
                        sortable: true,
                        editable: false
                    }, {
                        name: "description",
                        label: "Result",
                        cell: "string",
                        sortable: true,
                        editable: false
                    }, {
                        name: "recording",
                        label: "Recording",
                        cell: TableCells.watchGameUriCell,
                        sortable: false,
                        editable: false
                    }],

                collection: this.model
            });

            this.paginator = new Backgrid.Extension.Paginator({
                collection: this.model
            });
         
            this.setDefaultVariantScores();
        },

        renderOptions: function() {

            var variantData = _.values(variantLookup.variants);
            var scoresTypeSelected = this.model.getScoresTypeSelected();

            this.$el.html(this.headingTemplate(
                {   username: this.model.username,
                    variants: variantData,
                    scoresTypeSelected: scoresTypeSelected }));
        },

        render: function() {

            this.renderOptions();

            $("#all-scores-grid").append(this.grid.render().$el);
            $("#all-scores-paginator").append(this.paginator.render().$el);

            return this;
        },

        refresh: function() {
            this.model.fetch();
            this.render();
        },

        login: function(userName) {
            this.model.setUserName(userName);
            this.render();
        },

        logout: function() {
            this.model.clearUserName();
            this.render();
        },

        activate: function() {
            //Model may be in an old-state, so refresh
            this.setDefaultVariantScores();
        },

        quit: function() {
            this.refresh();
        },

        setDefaultVariantScores: function() {
            this.model.setVariantTopScores(_.findWhere(_.values(variantLookup.variants), {default: true}).code);
            this.model.fetch();
        },

        selectUserScores: function(event) {

            event.preventDefault();

            this.model.setUserTopScores();
            this.refresh();
        },

        selectDailyScores: function(event) {

            event.preventDefault();

            this.model.setDailyTopScores();
            this.refresh();
        },

        selectAllScoresOptions: function(event) {
            
            event.preventDefault();

            if(!event.target.id) {
                return;
            }

            var codeAfterHyphenIndex = event.target.id.lastIndexOf("-")
            
            if(codeAfterHyphenIndex == -1) {
                return;
            }

            var code = event.target.id.substring(codeAfterHyphenIndex + 1);

            if(code in variantLookup.variants) {
                this.model.setVariantTopScores(code);
                this.refresh();
            }
        }
    });

    return AllScoresView;

});
