
<script>
    const botConfig = <?php print json_encode($botConfig, JSON_PRETTY_PRINT); ?>
</script>
<script>
    function loadBot() {
        const search = window.location.search;
        const body = document.getElementsByTagName('body')[0];
        body.innerHTML = `
                <div class="LawnBotFullPage">
                    <div class="LawnBotFullPage-container">
                        <iframe frameborder="0" width="100%" height="100%"
                        src="https://sales.lawnbot.biz/${botConfig.customerId}/${botConfig.botId}/${search}"
                        sandbox="allow-popups allow-top-navigation allow-scripts allow-same-origin allow-modals" />
                    </div>
                </div>
                `;
    }
    setTimeout(() => {
        loadBot();
    }, 500);

</script>
