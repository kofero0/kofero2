Pod::Spec.new do |spec|
    spec.name                     = 'presenter'
    spec.version                  = '0.0.019'
    spec.homepage                 = 'http://kofe.ro'
    spec.source                   = { :http=> ''}
    spec.authors                  = ''
    spec.license                  = ''
    spec.summary                  = 'Shared code artifact for kofero-ios'
    spec.vendored_frameworks      = 'build/cocoapods/framework/presenter.framework'
    spec.libraries                = 'c++'
                
                
                
    if !Dir.exist?('build/cocoapods/framework/presenter.framework') || Dir.empty?('build/cocoapods/framework/presenter.framework')
        raise "

        Kotlin framework 'presenter' doesn't exist yet, so a proper Xcode project can't be generated.
        'pod install' should be executed after running ':generateDummyFramework' Gradle task:

            ./gradlew :presenter:generateDummyFramework

        Alternatively, proper pod installation is performed during Gradle sync in the IDE (if Podfile location is set)"
    end
                
    spec.pod_target_xcconfig = {
        'KOTLIN_PROJECT_PATH' => ':presenter',
        'PRODUCT_MODULE_NAME' => 'presenter',
    }
                
    spec.script_phases = [
        {
            :name => 'Build presenter',
            :execution_position => :before_compile,
            :shell_path => '/bin/sh',
            :script => <<-SCRIPT
                if [ "YES" = "$OVERRIDE_KOTLIN_BUILD_IDE_SUPPORTED" ]; then
                  echo "Skipping Gradle build task invocation due to OVERRIDE_KOTLIN_BUILD_IDE_SUPPORTED environment variable set to \"YES\""
                  exit 0
                fi
                set -ev
                REPO_ROOT="$PODS_TARGET_SRCROOT"
                "$REPO_ROOT/../gradlew" -p "$REPO_ROOT" $KOTLIN_PROJECT_PATH:syncFramework \
                    -Pkotlin.native.cocoapods.platform=$PLATFORM_NAME \
                    -Pkotlin.native.cocoapods.archs="$ARCHS" \
                    -Pkotlin.native.cocoapods.configuration="$CONFIGURATION"
            SCRIPT
        }
    ]
                
end