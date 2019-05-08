<div class="content-container">

  <div class="columns max-width">
    <div class="column">
      <div class="card">
        <div class="card-content wrap">
          <div class="field">
            <label class="label">CSV Text</label>
            <div class="control">
              <textarea id="csv-string" class="textarea" placeholder="Lookup Table Data"></textarea>
            </div>
          </div>
          <div class="field">
            <div class="control">
              <button id="submit-csv" class="button is-link">Submit</button>
              <label class="checkbox is-pulled-right">
                <input id="separator_type" type="checkbox" class="checkbox">Use "|" as the key value separator?
              </label>

            </div>
          </div>
        </div>
      </div>

    </div>
    <div class="column">
      <div class="card">
        <div class="card-content wrap">
          <div class="field">
            <div class="field-elements">
              <label class="label result-label">Result</label><i class="fa fa-clone copy-text" title="Copy"></i>
              <div class="notification is-primary copied">Copied!</div>
            </div>

            <div class="control">
              <textarea contenteditable="true" id="parse-results" class="textarea" placeholder="Result"></textarea>
            </div>
          </div>
        </div>
      </div>

    </div>
  </div>
</div>
